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
		using  thread_id_type     = std::uint32_t;
		
		struct size;
		struct position;

	public:
		frame_base (size, position);
		~frame_base();

	private:	
		void resize (const size&)    ;
		void move_to(const position&);

	protected:
		thread_id_type     __M_fbase_thread_id;
		native_handle_type __M_fbase_handle   ;
	};
}