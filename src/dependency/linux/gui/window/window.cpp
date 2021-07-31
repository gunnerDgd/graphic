#include <graphic/gui/window/window.hpp>

graphic::gui::window::window   (point_2d_int& w_pos         , point_2d_int& w_size,
                                int32_t       w_border_width, window      * w_parent)
                                : window_position(w_pos) ,
                                  window_size    (w_size),

{
    GET_DISPLAY_HANDLE(window_handle)  = XOpenDisplay       (nullptr);
    GET_WINDOW_HANDLE (window_handle)  = XCreateSimpleWindow(EXTRACT_HANDLE(window_handle)            ,
                                                             EXTRACT_2DIPOS(w_pos)                    ,
                                                             EXTRACT_2DIPOS(w_size)                   ,
                                                             w_border_width                           ,
                                                             BlackPixel(EXTRACT_HANDLE(window_handle)),  // Default Pixel Value
                                                             WhitePixel(EXTRACT_HANDLE(window_handle))); // Default Pixel Value

    window_parent                      = (!w_parent) ? XDefaultRootWindow(GET_DISPLAY_HANDLE(window_handle)) 
                                                     : GET_WINDOW_HANDLE (w_parent->native_handle());
}

void graphic::gui::window::show()
{
    XMapWindow(EXTRACT_HANDLE(window_handle));
    XFlush    ();
}

void graphic::gui::window::set_window_size    (point_2d_int& ws) { XResizeWindowSize(EXTRACT_HANDLE(window_handle), EXTRACT_2DIPOS(ws)); window_size     = ws; }
void graphic::gui::window::set_window_position(point_2d_int& wp) { XMoveWindow      (EXTRACT_HANDLE(window_handle), EXTRACT_2DIPOS(ws)); window_position = wp; }

void graphic::gui::window::set_border_pixmap    (pixmap& px)     { XSetWindowBorderPixmap    (EXTRACT_HANDLE(window_handle), px); }
void graphic::gui::window::set_background_pixmap(pixmap& px)     { XSetWindowBackgroundPixmap(EXTRACT_HANDLE(window_handle), px); }