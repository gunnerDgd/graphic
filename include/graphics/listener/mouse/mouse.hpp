#pragma once
#include <graphics/listener/mouse/mouse_map.hpp>
#include <future>



namespace graphics::window::listener {
	class mouse
	{
		template <typename ButtonMapped> class button;
	public:
		using native_handle_type  = HWND;
		using native_message_type = MSG ;
	public:
		class wheel   ;
		class movement;

	public: // Forwarding Information.
		using left   = button<details::lbutton_map>;
		using right  = button<details::rbutton_map>;
		using middle = button<details::wheel_map>  ;
		
	public:
		using thread_id = std::uint32_t;
			  thread_id		thread_domain();
	public:
		void				dispatch     (); // Dispatch Message to Dedicated Slots
		native_message_type get_message  (); // Only Get Message, Not Dispatch that.

	private:
		native_handle_type    __M_parent_window;
		details::message_slot __M_mouue_event_slot[6];
	};	
}

template <typename MouseReceiver> 
void graphics::window::listener::details::message_slot::operator=(MouseReceiver&& rcv)
{
	std::uint16_t							   rcv_index  = std::remove_reference_t<MouoseReceiver>::index;
	rcv.__M_mouse_event = __M_mouue_event_slot[rcv_index].__M_msgslot_event.get_future();

	return *this;
}