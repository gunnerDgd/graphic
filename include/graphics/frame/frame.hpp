#pragma once
#include <graphics/frame/frame_base.hpp>

namespace graphics::window {
	class frame
	{
		details::frame_base __M_frame_base;
	public:
		using  native_handle_type = typename details::frame_base::native_handle_type;
		using  size				  = typename details::frame_base::size			    ;
		using  position			  = typename details::frame_base::position		    ;
		class  dispatcher; // Necessary For "Dispatchable" Requirement.
	public:
		frame(const frame&) ;
		frame(const frame&&);
		template <typename FrameSize, typename FramePos,
				  typename = typename std::enable_if_t<std::is_same_v<std::remove_reference_t<FrameSize>, size>
													&& std::is_same_v<std::remove_reference_t<FramePos> , position>>>
		frame(FrameSize&& fr_size, FramePos&& fr_pos)
			: __M_frame_base(fr_size, fr_pos) {  }

	public:
		void			   resize		(const size&)	 ; // Necessary for "ResizableObject" Requirement.
		void			   move_to		(const position&); // Necessary for "MovableObject"   Requirement.
		native_handle_type native_handle()				 ; // Method that returns HWND.
	};
}