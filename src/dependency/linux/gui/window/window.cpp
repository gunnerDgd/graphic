#include <graphic/gui/window/window.hpp>

graphic::gui::window::window(point_2d_int& w_pos         , point_2d_int& w_size,
                             int32_t       w_border_width, window      * w_parent)
                             : window_position(w_pos),
                               window_size    (w_size)
{
    XSetWindowAttributes 
    window_display = XOpenDisplay (nullptr);
    window_parent  = (!w_parent) ? DefaultRootWindow() : w_parent;

    window_handle  = XCreateWindow(window_display     , window_parent      ,
                                   std::get<0>(w_pos) , std::get<1>(w_pos) ,
                                   std::get<0>(w_size), std::get<1>(w_size),
                                   w_border_width     ,
                                   InputOutput        ,
                                   TrueColor          ,
                                   0                  ,

                                   );
    XMapWindow                    (window_display, window_handle);
}