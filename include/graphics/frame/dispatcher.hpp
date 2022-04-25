#pragma once
#include <graphics/frame/frame.hpp>
#include <thread>

#define GRAPHICS_WINDOW_DISPATCHER_POST_IF(thread_id, msg, filterLow, filterHigh)\
	if(msg.message > filterLow && msg.message < filterHigh && thread_id)\
		PostThreadMessage(thread_id, msg.message, msg.wParam, msg.lParam);

namespace graphics::window {
	class frame::dispatcher
	{
	public:
		using					thread_id			 = std::uint32_t;
		static inline constexpr thread_id null_state = 0;
		using					native_message		 = MSG;

		 dispatcher(const frame&);
		~dispatcher()		     ;

	public:
										native_message dispatch   ();
		template <typename CompareExec> native_message dispatch_if(CompareExec&&);

	private:
		const frame& __M_disp_frame	  ;
		thread_id    __M_disp_mouse   ,
				     __M_disp_keyboard;
	};
}

template <typename CompareExec> 
typename graphics::window::frame::dispatcher::native_message 
		 graphics::window::frame::dispatcher::dispatch_if(CompareExec&& comp)
{
	native_message    msg_recv;
	if (!comp(msg_recv))
		return msg_recv;
	
	GetMessage      (&msg_recv, __M_disp_frame.__M_frame_base.__M_fbase_handle, 0, 0);
	TranslateMessage(&msg_recv);
	
	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_mouse   , msg_recv, WM_MOUSEFIRST, WM_MOUSELAST)
	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_keyboard, msg_recv, WM_KEYFIRST  , WM_KEYLAST)

	return msg_recv;
}