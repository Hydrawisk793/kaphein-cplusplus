#ifndef KAPHEIN_MATH_NUMBERTRAITS_HPP
#define KAPHEIN_MATH_NUMBERTRAITS_HPP

#include <cstdint>
#include "kaphein/pp/basic.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct NumericTraits
    {
        static const E zero = E();

        static const E one = E(1);

        static const E epsilon = E();
    };

    template <>
    struct NumericTraits<float>
    {
        static const float zero;

        static const float one;

        static const float epsilon;
    };

    template <>
    struct NumericTraits<double>
    {
        static const double zero;

        static const double one;

        static const double epsilon;
    };

    template <>
    struct NumericTraits<long double>
    {
        static const long double zero;

        static const long double one;

        static const long double epsilon;
    };
}
}

#endif
