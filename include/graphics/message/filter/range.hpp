#pragma once
#include <Windows.h>
#include <type_traits>

namespace graphics::window::messaging::filter {
	template <std::uint16_t Begin, std::uint16_t End>
	struct ranged_filter
	{
		static constexpr std::uint16_t begin = Begin;
		static constexpr std::uint16_t end   = End  ;
	};

	using all		    = ranged_filter<0, 0>;
	using mouse_only    = ranged_filter<WM_MOUSEFIRST, WM_MOUSELAST>;
	using keyboard_only = ranged_filter<WM_KEYFIRST  , WM_KEYLAST>  ;
}

namespace graphics::window::messaging {
	inline constexpr filter::all		   all		    {};
	inline constexpr filter::mouse_only    mouse_only   {};
	inline constexpr filter::keyboard_only keyboard_only{};
}