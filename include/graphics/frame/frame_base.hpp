#pragma once
#include <graphics/frame/declare.hpp>

#include <Windows.h>
#include <type_traits>

namespace graphics::window::details {
	class frame_base
	{
		friend class graphics::window::frame;
	public:
		using  native_handle_type = HWND;
		struct size
		{
			friend class frame_base;			
			using		 size_type = std::uint16_t;
			size		(size_type, size_type);

		private:
			size_type __M_frame_size_x,
					  __M_frame_size_y;
		};

		struct position
		{
			friend class frame_base;
			using		 position_type = std::uint16_t;
			position	(position_type, position_type);

		private:
			position_type __M_position_x,
						  __M_position_y;
		};

	public:
		frame_base (size, position);
		~frame_base();

	private:	
		void resize (const size&)    ;
		void move_to(const position&);

	protected:
		native_handle_type __M_fbase_handle  ;
		size			   __M_fbase_size    ;
		position		   __M_fbase_position;
	};
}