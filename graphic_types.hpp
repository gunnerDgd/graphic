#include <tuple>

namespace graphic {

    using point_2d_int   = std::tuple<uint32_t, uint32_t>;
    using point_2d_float = std::tuple<double  , double>  ;

    using point_3d_int   = std::tuple<uint32_t, uint32_t, uint32_t>;
    using point_3d_float = std::tuple<double  , double   , double> ;
}