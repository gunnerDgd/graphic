#pragma once
#include <graphics/frame/frame_base.hpp>

namespace graphics::window::details {
	struct frame_base::size
	{
		friend class frame_base;
		using		 size_type = std::uint16_t;
		size		(size_type, size_type);

	private:
		size_type __M_frame_size_x,
				  __M_frame_size_y;
	};

	struct frame_base::position
	{
		friend class frame_base;
		using		 position_type = std::uint16_t;
		position	(position_type, position_type);

	private:
		position_type __M_position_x,
					  __M_position_y;
	};
}