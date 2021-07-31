#include <tuple>

namespace graphic {

    using point_2d_int   = std::tuple<uint32_t, uint32_t>;
    using point_2d_float = std::tuple<double  , double>  ;

    using point_3d_int   = std::tuple<uint32_t, uint32_t, uint32_t>;
    using point_3d_float = std::tuple<double  , double   , double> ;

#define X_POS(p) std::get<0>(p)
#define Y_POS(p) std::get<1>(p)
#define Z_POS(p) std::get<2>(p)

#define EXTRACT_2DIPOS(p) std::get<0>(p), std::get<1>(p)
}