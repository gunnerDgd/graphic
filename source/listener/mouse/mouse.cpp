#include <graphics/listener/mouse/mouse.hpp>

typename graphics::window::messaging::system_message 
		 graphics::window::listener::mouse::get()
{
	return messaging::system_message::get(messaging::mouse_only);
}

void graphics::window::listener::mouse::dispatch(messaging::system_message& msg)
{
	
}