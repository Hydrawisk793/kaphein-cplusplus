#ifndef KARBONATOR_MATH_POW_HPP
#define KARBONATOR_MATH_POW_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Pow
    {
        E operator ()(const E& x, const E& y)
        {
            return UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Pow<float>
    {
        float operator ()(const float& x, const float& y);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Pow<double>
    {
        double operator ()(const double& x, const double& y);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Pow<long double>
    {
        long double operator ()(const long double& x, const long double& y);
    };
}
}

#endif
