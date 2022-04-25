#pragma once

namespace graphics::window {
	struct					  window_category {};
	struct button	 : public window_category { static inline constexpr const wchar_t* value = L"BUTTON"  ; };
	struct combo_box : public window_category { static inline constexpr const wchar_t* value = L"COMBOBOX"; };
	struct edit_box  : public window_category { static inline constexpr const wchar_t* value = L"EDIT"	  ; };
}