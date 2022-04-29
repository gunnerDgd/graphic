#pragma once
#include <graphics/frame/frame.hpp>
#include <graphics/frame/dispatcher/dispatch_slot.hpp>

#include <thread>

namespace graphics::window {
	class frame::dispatcher
	{
	public:
		 dispatcher(const frame&);
		~dispatcher()		     ;

	public:
		template <typename CompareExec> 
		messaging::system_message dispatch_if(CompareExec&&);
		messaging::system_message dispatch   ();

	public:
		enum class						   index : std::uint8_t { mouse = 0, keyboard = 1 };
		details::dispatch_slot& operator[](index);
		
	private:
		const frame&		   __M_disp_frame;
		details::dispatch_slot __M_disp_msgslot[4];
	};
}

template <typename CompareExec> 
typename graphics::window::messaging::system_message
		 graphics::window::frame::dispatcher::dispatch_if(CompareExec&& comp)
{
	messaging::system_message msg_recv  = messaging::system_message::get();
	if (!comp(msg_recv)) return;

	messaging::system_message::post_if(messaging::filter::mouse_only, 
									  __M_disp_msgslot[0].domain(), msg_recv);
	messaging::system_message::post_if(messaging::filter::keyboard_only, 
									  __M_disp_msgslot[1].domain(), msg_recv);

	return msg_recv;
}