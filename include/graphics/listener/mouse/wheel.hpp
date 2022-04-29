#pragma once
#include <graphics/listener/mouse/mouse.hpp>

namespace graphics::window::listener {
	class mouse::wheel
	{
		friend class mouse;
		static constexpr std::uint16_t index = 6;
		
		struct delta					    { std::uint16_t x, y, wheel_delta; };
		using  event_type = std::future<MSG>;
			   event_type __M_mouse_event   ;
	public:
		delta operator()();
	};
}

