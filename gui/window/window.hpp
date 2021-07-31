#include <graphic/gui/window/window_types.hpp>

namespace graphic {
namespace gui     {

    class window
    {
    public:
        window(point_2d_int& w_pos         ,
               point_2d_int& w_size        ,
               int32_t       w_border_width,
               window      * w_parent      = nullptr
               );,


    public:
        window_handle_t   native_handle() { return window_handle; }

    protected:
        window_handle_t   window_parent,
                          window_handle;

#ifdef ENVIRONMENT_UNIX
        display_handle_t* window_display         ;
#endif
    
    protected:
        point_2d_int     window_position,
                         window_size    ;
    };
}
}

