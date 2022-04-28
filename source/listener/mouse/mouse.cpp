#include <graphics/listener/mouse/mouse.hpp>



typename graphics::window::listener::mouse::thread_id 
		 graphics::window::listener::mouse::thread_domain() { return GetCurrentThreadId(); }

void     graphics::window::listener::mouse::dispatch()
{
	MSG		    msg_recv;
	GetMessage(&msg_recv, 0, WM_MOUSEFIRST, WM_MOUSELAST);

	
}