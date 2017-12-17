#ifndef KAPHEIN_MATH_ISZERO_HPP
#define KAPHEIN_MATH_ISZERO_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "kaphein/cplusplus/math/NumericTraits.hpp"
#include "kaphein/cplusplus/math/Equal.hpp"

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
