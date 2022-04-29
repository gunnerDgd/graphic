#pragma once
#include <graphics/message/declare.hpp>
#include <graphics/message/filter/range.hpp>

namespace graphics::window::messaging::filter {
	template <typename... FilterType>
	struct filter;

	template <std::uint16_t Begin, std::uint16_t End>
	struct filter<ranged_filter<Begin, End>>
	{
		friend class graphics::window::messaging::system_message;
		using			 range					  = ranged_filter<Begin, End>;
		using			 target_handle			  = HWND;
		static constexpr target_handle all_handle = 0;

		filter(target_handle target = 0) : __M_filter_hwnd(target) {  }
	private:
		GRAPHICS_MESSAGING_INTERNAL(target_handle, window_handle)
	};
}