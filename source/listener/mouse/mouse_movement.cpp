#include <graphics/listener/mouse/movement.hpp>

typename graphics::window::listener::mouse::movement::position 
		 graphics::window::listener::mouse::movement::operator()()
{
						   __M_mouse_event.wait();
	MSG      evt_message = __M_mouse_event.get ();
	position evt_position;

	evt_position.x			  = evt_message.lParam & 0xFFFF;
	evt_position.y			  = evt_message.lParam >> 16   ; return evt_position;
}