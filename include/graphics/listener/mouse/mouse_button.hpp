#pragma once
#include <graphics/listener/mouse/mouse.hpp>

namespace graphics::window::listener {
	template <typename ButtonInfo>
	class mouse::button
	{
	public:
		using	   native_message = MSG;
		using	   event_map	  = ButtonInfo;
		enum class events		  : UINT
		{ 
			clicked		   = event_map::clicked		  ,
			released	   = event_map::released	  ,
			double_clicked = event_map::double_clicked
		};

	public:
		events operator()();

	private:
		mouse& __M_event_source;
	};
}

template <typename ButtonInfo>
typename graphics::window::listener::mouse::button<ButtonInfo>::events
		 graphics::window::listener::mouse::button<ButtonInfo>::operator()()
{
	native_message mouse_msg;
	GetMessage   (&mouse_msg, __M_event_source.__M_parent_window, event_map::filter_begin, 
																  event_map::filter_max) ;

	return static_cast<events>(mouse_msg.message);
}