#ifndef KARBONATOR_MATH_ISZERO_HPP
#define KARBONATOR_MATH_ISZERO_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/math/NumericTraits.hpp"
#include "karbonator/math/Equal.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct IsZero
    {
        bool operator ()(const E& v, const E& epsilon = NumericTraits<E>::epsilon)
        {
            return Equal<E>()(v, NumericTraits<E>::zero, epsilon);
        }
    };
}
}

#endif
