#pragma once
#include <graphics/listener/mouse/mouse.hpp>

namespace graphics::window::listener {
	class mouse::movement
	{
		static constexpr  std::uint16_t index = 7;
		struct position { std::uint16_t x, y; };

		using event_type = std::future<MSG>;
			  event_type __M_mouse_event;
	
	public:
		position operator()();
	};
}