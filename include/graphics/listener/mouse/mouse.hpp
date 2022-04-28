#pragma once
#include <graphics/listener/mouse/mouse_map.hpp>
#include <future>

namespace graphics::window::listener {
	class mouse
	{
	public:
		using native_handle_type = HWND;
		using thread_id			 = std::uint32_t;
		class message_slot
		{
			friend class mouse;
			using		 event_type = std::promise<MSG>;
						 event_type __M_msgslot_event  ;
		
		public:
			template <typename MouseReceiver> mouse& operator+=(MouseReceiver&&);
		};
	public:
		template <typename ButtonMapped> class button  ;
										 class wheel   ;
										 class movement;

		using left  = button<details::lbutton_map>;
		using right = button<details::rbutton_map>;
		
	public:
		thread_id thread_domain();
		void      dispatch	   ();

	private:
		native_handle_type __M_parent_window;
		message_slot	   __M_mouue_event_slot[6];
	};	
}

template <typename MouseReceiver> 
graphics::window::listener::mouse&
graphics::window::listener::mouse::message_slot::operator+=(MouseReceiver&& rcv)
{
	std::uint16_t							   rcv_index  = std::remove_reference_t<MouoseReceiver>::index;
	rcv.__M_mouse_event = __M_mouue_event_slot[rcv_index].__M_msgslot_event.get_future();

	return *this;
}