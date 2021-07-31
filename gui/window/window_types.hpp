#include <X11/X.h>
#include <X11/xlib.h>

#include <graphic/graphic_types.hpp>

namespace graphic {
namespace gui     {

#ifdef ENVIRONMENT_UNIX
    using window_handle_t  = Window ;
    using display_handle_t = Display;
#elif  ENVIRONMENT_WINDOWS
    using window_handle_t = HANDLE;
#endif
}
}