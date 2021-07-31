#include <graphic/gui/window/window_define.hpp>

namespace graphic {
namespace gui     {

    class rgb
    {
    public:
        union
        {
            uint32_t rgb_int_type;
            struct
            {
                uint8_t red   : 8;
                uint8_t green : 8;
                uint8_t blue  : 8;
                uint8_t alpha : 8;
            };
        }
    };

    class colormap
    {
    public:
        colormap(window_handle_t& cm_wnd, )
    };
}
}