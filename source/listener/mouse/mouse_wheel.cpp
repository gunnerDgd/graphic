#include <graphics/listener/mouse/wheel.hpp>

typename graphics::window::listener::mouse::wheel::delta 
		 graphics::window::listener::mouse::wheel::operator()()
{
					    __M_mouse_event.wait();
	MSG   evt_message = __M_mouse_event.get ();
	delta evt_delta;

	evt_delta.x			  = evt_message.lParam & 0xFFFF;
	evt_delta.y			  = evt_message.lParam >> 16   ;
	evt_delta.wheel_delta = evt_message.wParam >> 32   ; return evt_delta;
}