#ifndef KAPHEIN_MATH_LERP_HPP
#define KAPHEIN_MATH_LERP_HPP

#include "kaphein/pp/basic.hpp"
#include "NumericTraits.hpp"

namespace kaphein
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
