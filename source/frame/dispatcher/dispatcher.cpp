#include <graphics/frame/dispatcher/dispatcher.hpp>
	
graphics::window::frame::dispatcher:: dispatcher(const frame& fr_source) : __M_disp_frame(fr_source) {  }
graphics::window::frame::dispatcher::~dispatcher()													 {  }

graphics::window::details::dispatch_slot& 
graphics::window::frame::dispatcher::operator[](index idx)
{
	return __M_disp_frame_msgslot[static_cast<std::underlying_type_t<index>>(idx)];
}

typename graphics::window::frame::dispatcher::native_message 
		 graphics::window::frame::dispatcher::dispatch()
{
	native_message    msg_recv;
	
	GetMessage      (&msg_recv, __M_disp_frame.__M_frame_base.__M_fbase_handle, 0, 0);
	TranslateMessage(&msg_recv);

	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_frame_msgslot[__mouse::value]   .__M_slot_thread, msg_recv, WM_MOUSEFIRST, WM_MOUSELAST)
	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_frame_msgslot[__keyboard::value].__M_slot_thread, msg_recv, WM_KEYFIRST  , WM_KEYLAST)
	
	return msg_recv;
}