#ifndef KARBONATOR_MATH_ABS_HPP
#define KARBONATOR_MATH_ABS_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"
#include "NumericTraits.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Abs
    {
        E operator ()(const E& value)
        {
            return (value < NumericTraits<E>::zero ? -value : value);
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Abs<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Abs<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Abs<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
