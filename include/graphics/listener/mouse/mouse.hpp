#pragma once
#include <graphics/message/filter/filter.hpp>
#include <graphics/message/system_message.hpp>
#include <graphics/message/domain/thread_domain.hpp>

#include <graphics/listener/mouse/details/mouse_map.hpp>

#include <future>

namespace graphics::window::listener {
	class mouse
	{
		template <typename ButtonMapped>   class button;
		template <std::uint8_t EventIndex> class event_slot;
	public:
		class wheel   ;
		class movement;

	public: // Forwarding Information.
		using left   = button<details::lbutton_map>;
		using right  = button<details::rbutton_map>;
		using middle = button<details::wheel_map>  ;
	public:
		messaging::domain::thread_domain& current_domain();
		void							  dispatch	    (messaging::system_message&); // Dispatch Message to Dedicated Slots
		messaging::system_message		  get		    (); // Only Get Message, Not Dispatch that.

	private:
		messaging::domain::thread_domain __M_mouse_domain;
		
	};	
}