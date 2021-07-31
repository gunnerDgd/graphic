#include <graphic/gui/pixmap/pixmap.hpp>

graphic::gui::pixmap::pixmap(window_handle_t& px_window, point_2d_int& px_size, uint32_t px_depth)
{
    pixmap_handle = XCreatePixmap(px_window.first     , px_window.second    , 
                                  std::get<0>(px_size), std::get<1>(px_size), px_depth);
}