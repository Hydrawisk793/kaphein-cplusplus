#ifndef KARBONATOR_MATH_LERP_HPP
#define KARBONATOR_MATH_LERP_HPP

#include "karbonator/pp/basic.hpp"
#include "NumericTraits.hpp"

namespace karbonator
{
namespace math
{
    template <typename E, typename S>
    struct Lerp
    {
        E operator ()(const E& start, const E& end, const S& delta) {
            return start * ((NumbericTraits<E>::one) - delta) + end * delta;
        }
    };
}
}

#endif
