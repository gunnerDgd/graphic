#pragma once
#include <Windows.h>
#include <cstdint>

#include <thread>

namespace graphics::window::listener {
	class mouse
	{
	public:
		using native_handle_type = HWND;
	public:
		template <typename ButtonInfo>
		class  button  ;
		class  wheel   ;
		class  movement;

		struct left_button_info ;
		struct right_button_info;

		using  left  = button<left_button_info> ;
		using  right = button<right_button_info>;

	public:
		template <typename WindowType>
		mouse(WindowType&& wnd) : __M_parent_window(wnd.native_handle()) {}

	private:
		native_handle_type __M_parent_window;
	};

	struct mouse::left_button_info
	{
		using					event_type				  = std::uint16_t   ;
		using					filter_type				  = std::uint16_t   ;

		static inline constexpr event_type  clicked		   = WM_LBUTTONDOWN  ;
		static inline constexpr event_type  released	   = WM_LBUTTONUP	 ;
		static inline constexpr event_type  double_clicked = WM_LBUTTONDBLCLK;
		
		static inline constexpr filter_type filter_begin   = 0x201			 ;
		static inline constexpr filter_type filter_end     = 0x203			 ;
	};

	struct mouse::right_button_info
	{
		using					event_type				   = std::uint16_t   ;
		using					filter_type				   = std::uint16_t   ;

		static inline constexpr event_type  clicked		   = WM_RBUTTONDOWN  ;
		static inline constexpr event_type  released	   = WM_RBUTTONUP	 ;
		static inline constexpr event_type  double_clicked = WM_RBUTTONDBLCLK;

		static inline constexpr filter_type filter_begin   = 0x204			 ;
		static inline constexpr filter_type filter_end     = 0x206			 ;
	};
}