#pragma once
#include <graphics/frame/frame.hpp>
#include <graphics/message/system_message.hpp>
#include <graphics/message/filter/filter.hpp>

#include <thread>

#define GRAPHICS_WINDOW_DISPATCHER_HELPER(name, parent, id)   struct name : public parent { static inline constexpr std::uint16_t value = id; };
#define GRAPHICS_WINDOW_DISPATCHER_STATIC(name, type, id) static inline constexpr type name {  };

#define GRAPHICS_WINDOW_DISPATCHER_POST_IF(thread_id, msg, filterLow, filterHigh)\
	if(msg.message > filterLow && msg.message < filterHigh && thread_id)\
		PostThreadMessage(thread_id, msg.message, msg.wParam, msg.lParam);

namespace graphics::window {
	class frame::dispatcher
	{
	public:
		using					thread_id = std::uint32_t;
		static inline constexpr thread_id null_state = 0;

		using					native_message = MSG;
		class				    message_slot
		{
			friend class frame::dispatcher;
			thread_id									__M_slot_thread;
			message_slot(thread_id init = null_state) : __M_slot_thread(init) {}

		public:
			template <typename ReceiverType>
			void operator=(ReceiverType&& rcv) { __M_slot_thread = rcv.thread_domain(); }
		};

	private:
		struct										  dispatch_slot {};
		GRAPHICS_WINDOW_DISPATCHER_HELPER(__mouse   , dispatch_slot, 0)
		GRAPHICS_WINDOW_DISPATCHER_HELPER(__keyboard, dispatch_slot, 1)

	public:
		GRAPHICS_WINDOW_DISPATCHER_STATIC(mouse   , __mouse)
		GRAPHICS_WINDOW_DISPATCHER_STATIC(keyboard, __keyboard)
		
	public:
		 dispatcher(const frame&);
		~dispatcher()		     ;

	public:
										native_message dispatch   ();
		template <typename CompareExec> native_message dispatch_if(CompareExec&&);

	public:
		template <typename SlotType> 
		std::enable_if_t<std::is_same_v<SlotType, dispatch_slot>, message_slot&>
			operator[](SlotType) { return __M_disp_frame_msgslot[SlotType::value]; }

		template <typename SlotType>
		std::enable_if_t<!std::is_same_v<SlotType, dispatch_slot>>
			operator[](SlotType) {  }

	private:
		const frame& __M_disp_frame;
		message_slot __M_disp_frame_msgslot[4];
	};
}

template <typename CompareExec> 
typename graphics::window::frame::dispatcher::native_message 
		 graphics::window::frame::dispatcher::dispatch_if(CompareExec&& comp)
{
	messaging::system_message msg_recv = messaging::system_message::get();
	
	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_frame_msgslot[__mouse::value]   .__M_slot_thread, msg_recv, WM_MOUSEFIRST, WM_MOUSELAST)
	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_frame_msgslot[__keyboard::value].__M_slot_thread, msg_recv, WM_KEYFIRST  , WM_KEYLAST)

	return msg_recv;
}