#ifndef KARBONATOR_MATH_NUMBERTRAITS_HPP
#define KARBONATOR_MATH_NUMBERTRAITS_HPP

#include <cstdint>
#include "karbonator/pp/basic.hpp"

namespace karbonator
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
    struct KARBONATOR_PP_DLL_API NumericTraits<float>
    {
        static const float zero;

        static const float one;

        static const float epsilon;
    };

    template <>
    struct KARBONATOR_PP_DLL_API NumericTraits<double>
    {
        static const double zero;

        static const double one;

        static const double epsilon;
    };

    template <>
    struct KARBONATOR_PP_DLL_API NumericTraits<long double>
    {
        static const long double zero;

        static const long double one;

        static const long double epsilon;
    };
}
}

#endif
