#pragma once
#include <graphics/listener/mouse/mouse.hpp>
#include <future>

namespace graphics::window::listener {
	template <typename ButtonMapped>
	class mouse::button
	{
		template <std::uint16_t IndexId> class __button_event;
	public:
		using	   native_message = MSG;
		using	   button_map	  = ButtonMapped;
		struct	   position		   { std::uint16_t x, y; };
		
	public:
		using clicked		 = __button_event<button_map::index_value>;
		using double_clicked = __button_event<button_map::index_value + 1>;
		using released		 = __button_event<button_map::index_value + 2>;
	};

	template <typename ButtonMapped>
	template <std::uint16_t IndexId>
	class mouse::button<ButtonMapped>::__button_event
	{
		static constexpr std::uint16_t index = IndexId;
		friend class mouse;
		using		 event_type = std::future<MSG>;
					 event_type  __M_mouse_event;
	public:
		button::position operator()();
	};
}

template <typename ButtonMapped>
template <std::uint16_t IndexId>
typename graphics::window::listener::mouse::button<ButtonMapped>::position
		 graphics::window::listener::mouse::button<ButtonMapped>::__button_event<IndexId>::operator()()
{
					  __M_mouse_event.wait();
	MSG evt_message = __M_mouse_event.get ();
	
	return position { evt_message.lParam & 0xFFFF, 
					  evt_message.lParam >> 16}  ;
}
