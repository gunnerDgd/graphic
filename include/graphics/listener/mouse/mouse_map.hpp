#pragma once
#include <Windows.h>
#include <cstdint>

#define GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(type, name, value) static inline constexpr type name = value;

namespace graphics::window::listener::details {
	struct lbutton_map
	{
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, index_value   , 0)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, clicked	   , WM_LBUTTONDOWN)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, released	   , WM_LBUTTONUP)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, double_clicked, WM_LBUTTONDBLCLK)
	};

	struct rbutton_map
	{
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, index_value   , 3)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, clicked	   , WM_RBUTTONDOWN)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, released	   , WM_RBUTTONUP)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, double_clicked, WM_RBUTTONDBLCLK)
	};

	struct wheel_map
	{
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, index_value   , 3)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, clicked	   , WM_MBUTTONDOWN)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, released	   , WM_MBUTTONUP)
		GRAPHICS_WINDOW_LISTENER_MOUSE_STATIC(std::uint16_t, double_clicked, WM_MBUTTONDBLCLK)
	};
}