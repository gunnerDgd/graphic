#pragma once
#include <tuple>

#ifdef ENVIRONMENT_UNIX

#define GET_WINDOW_HANDLE(h)  std::get<1>(h)
#define GET_DISPLAY_HANDLE(h) std::get<0>(h)

#define SET_WINDOW_HANDLE(h, n) std::get<1>(h) = n
#define SET_DISPLAY_HANDLE(h, n) std::get<0>(h) = n

#define EXTRACT_HANDLE(h) std::get<0>(h), std::get<1>(h)

#endif
