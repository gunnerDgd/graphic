#include <graphics/frame/frame_base.hpp>

graphics::window::details::frame_base::size::size(size_type x, size_type y)
	: __M_frame_size_x(x),
	  __M_frame_size_y(y) {  }

graphics::window::details::frame_base::position::position(position_type x, position_type y)
	: __M_position_x(x),
	  __M_position_y(y) {  }

graphics::window::details::frame_base::frame_base(size fr_size, position fr_pos)
	: __M_fbase_position(fr_pos),
	  __M_fbase_size    (fr_size)
{
	__M_fbase_handle = CreateWindowA(nullptr, nullptr, WS_CAPTION, 
									 fr_pos .__M_position_x  ,
									 fr_pos .__M_position_y  ,
								     fr_size.__M_frame_size_x,
									 fr_size.__M_frame_size_y,
									 nullptr, nullptr, nullptr, nullptr);
	WNDCLASS	   fr_conf ;
	RegisterClass(&fr_conf);
}

graphics::window::details::frame_base::~frame_base()
{
	
}