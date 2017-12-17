#ifndef KAPHEIN_MATH_ISZERO_HPP
#define KAPHEIN_MATH_ISZERO_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/math/NumericTraits.hpp"
#include "kaphein/math/Equal.hpp"

namespace kaphein
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
