#include <graphics/frame/dispatcher.hpp>
	
graphics::window::frame::dispatcher:: dispatcher(const frame& fr_source) : __M_disp_frame(fr_source) {  }
graphics::window::frame::dispatcher::~dispatcher()													 {  }

typename graphics::window::frame::dispatcher::native_message 
		 graphics::window::frame::dispatcher::dispatch()
{
	native_message    msg_recv;
	
	GetMessage      (&msg_recv, __M_disp_frame.__M_frame_base.__M_fbase_handle, 0, 0);
	TranslateMessage(&msg_recv);

	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_mouse   , msg_recv, WM_MOUSEFIRST, WM_MOUSELAST)
	GRAPHICS_WINDOW_DISPATCHER_POST_IF(__M_disp_keyboard, msg_recv, WM_KEYFIRST  , WM_KEYLAST)
	
	return msg_recv;
}