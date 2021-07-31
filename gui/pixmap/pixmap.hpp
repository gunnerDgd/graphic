#include <graphic/gui/window/window_types.hpp>

namespace graphic {
namespace gui     {
    class pixmap
    {
    public:
        pixmap(window_handle_t& px_window, point_2d_int& px_size, uint32_t px_depth);
        pixmap(pixmap_t         px_copy);

    public:
        pixmap_t handle() { return pixmap_handle; }

    protected:
        pixmap_t pixmap_handle;
    };
}
}