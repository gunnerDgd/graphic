#include <graphics/frame/frame_base.hpp>
#include <graphics/frame/frame_configuration.hpp>

namespace graphics::window::details {
	LRESULT default_callback(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) { return DefWindowProc(wnd, msg, wparam, lparam); }
}

graphics::window::details::frame_base::size::size(size_type x, size_type y)
	: __M_frame_size_x(x),
	  __M_frame_size_y(y) {  }

graphics::window::details::frame_base::position::position(position_type x, position_type y)
	: __M_position_x(x),
	  __M_position_y(y) {  }

graphics::window::details::frame_base::frame_base(size fr_size, position fr_pos)
	 : __M_fbase_thread_id(GetCurrentThreadId())
{
	__M_fbase_handle = CreateWindowA(nullptr, nullptr, WS_CAPTION, 
									 fr_pos .__M_position_x  ,
									 fr_pos .__M_position_y  ,
								     fr_size.__M_frame_size_x,
									 fr_size.__M_frame_size_y,
									 nullptr, nullptr, nullptr, nullptr); // Hazardous.
	WNDCLASS	   fr_conf;
				   fr_conf.lpfnWndProc = (WNDPROC)&default_callback;
	RegisterClass(&fr_conf);
	SetWindowLong(__M_fbase_handle, GWL_USERDATA, reinterpret_cast<LONG>(this));
}

graphics::window::details::frame_base::~frame_base()
{
	DestroyWindow(__M_fbase_handle);
}

void graphics::window::details::frame_base::resize(const size& size)
{
	MoveWindow()
}

void graphics::window::details::frame_base::move_to(const position&)
{

}