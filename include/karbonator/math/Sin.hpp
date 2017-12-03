#ifndef KARBONATOR_MATH_SIN_HPP
#define KARBONATOR_MATH_SIN_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Sin
    {
        E operator ()(const E& radian)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sin<float>
    {
        float operator ()(const float& radian);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sin<double>
    {
        double operator ()(const double& radian);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sin<long double>
    {
        long double operator ()(const long double& radian);
    };
}
}

#endif
