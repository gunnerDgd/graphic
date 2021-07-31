#include <graphic/gui/window/window_types.hpp>
#include <graphic/gui/pixmap/pixmap.hpp>

namespace graphic {
namespace gui     {

    class window
    {
    public:
        window(point_2d_int& w_pos, point_2d_int& w_size, int32_t w_border_width, window* w_parent = nullptr);

    public:
        void                   set_window_size      (point_2d_int&);
        void                   set_window_position  (point_2d_int&);
        
        void                   set_border_pixmap    (pixmap      &);
        void                   set_background_pixmap(pixmap      &);
    
    public:
        const point_2d_int&    get_window_size      () { return window_size    ; }
        const point_2d_int&    get_window_position  () { return window_position; }

    public:
        const window_handle_t& native_handle        () { return window_handle; }
        void                   show                 ();

    protected:
        Window          window_parent;
        window_handle_t window_handle;
        
    protected:
        point_2d_int    window_position,
                        window_size    ;
    };
}
}

