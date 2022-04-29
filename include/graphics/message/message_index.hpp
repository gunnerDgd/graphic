#pragma once
#include <Windows.h>
#include <type_traits>

namespace graphics::window::messaging::details {
	struct						   message_index {};
	struct category       : public message_index { typedef std::uint16_t type; };
	struct window_handle  : public message_index { typedef HWND		     type; };
	struct parameter	  : public message_index 
	{
		typedef struct
		{
			std::uint16_t w_param;
			std::uint64_t l_param;
		} type;
	};
}

namespace graphics::window::messaging {
	inline constexpr details::category  category;
	inline constexpr details::parameter parameter;
}