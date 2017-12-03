#ifndef KARBONATOR_MATH_ATAN_HPP
#define KARBONATOR_MATH_ATAN_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Atan
    {
        E operator ()(const E& value)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Atan<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Atan<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Atan<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
