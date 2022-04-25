#include <graphics/frame/frame.hpp>

typename graphics::window::frame::native_handle_type 
		 graphics::window::frame::native_handle()				   { return __M_frame_base.__M_fbase_handle; }

void	 graphics::window::frame::resize (const size	& fr_size) { __M_frame_base.resize (fr_size); }
void	 graphics::window::frame::move_to(const position& fr_move) { __M_frame_base.move_to(fr_move); }