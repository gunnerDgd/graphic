#pragma once
#include <type_traits>
#include <Windows.h>

namespace graphics::window::listener {
	template <std::uint32_t FilterBegin, std::uint32_t FilterEnd>
	struct message_filter
	{
		static inline constexpr std::uint32_t begin = FilterBegin;
		static inline constexpr std::uint32_t end   = FilterEnd  ;
	};

namespace filter {
	using mouse_only    = message_filter<WM_MOUSEFIRST, WM_MOUSELAST>;
	using keyboard_only = message_filter<WM_KEYFIRST  , WM_KEYLAST>  ;
}
}