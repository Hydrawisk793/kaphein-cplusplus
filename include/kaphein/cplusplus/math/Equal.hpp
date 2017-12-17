#ifndef KAPHEIN_MATH_EQUAL_HPP
#define KAPHEIN_MATH_EQUAL_HPP

//#include "kaphein/cplusplus/pp/basic.hpp"
#include "NumericTraits.hpp"
#include "Abs.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Equal
    {
        bool operator ()(const E & lhs, const E & rhs, const E & epsilon = NumericTraits<E>::epsilon)
        {
            return epsilon >= Abs<E>()(lhs - rhs);
        }
    };
}
}

#endif
