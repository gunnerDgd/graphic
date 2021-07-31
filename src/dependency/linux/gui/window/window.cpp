#include <graphic/gui/window/window.hpp>

graphic::gui::window::window   (point_2d_int& w_pos         , point_2d_int& w_size,
                                int32_t       w_border_width, window      * w_parent)
                                : window_position(w_pos),
                                  window_size    (w_size)
{
    window_parent  = (!w_parent) ? XDefaultRootWindow() 
                                 : w_parent->native_handle().first;

    
    window_handle  = XCreateWindow(window_display     , window_parent      ,
                                   std::get<0>(w_pos) , std::get<1>(w_pos) ,
                                   std::get<0>(w_size), std::get<1>(w_size),
                                   w_border_width     ,
                                   InputOutput        , // Fixed Value.
                                   TrueColor          , // Fixed Value.
                                   0                  ,
                                   
                                   );
    XMapWindow                    (window_display, window_handle);
}

bool graphic::gui::window::show()
{
    XMapWindow(window_handle.second, window_handle.first);
    XFlush    ();
}

void graphic::gui::window::set_window_size(point_2d_int& ws)
{
    XWindowChanges ws_change;

    ws_change.width  = std::get<0>(ws);
    ws_change.height = std::get<1>(ws);

    XConfigureWindow(window_handle.second, window_handle.first, 
                     CWWidth | CWHeight  , &ws_change        );
}
const point_2d_int& graphic::gui::window::get_window_size() { return window_size; }