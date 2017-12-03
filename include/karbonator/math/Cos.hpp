#ifndef KARBONATOR_MATH_COS_HPP
#define KARBONATOR_MATH_COS_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Cos
    {
        E operator ()(const E& radian)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Cos<float>
    {
        float operator ()(const float& radian);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Cos<double>
    {
        double operator ()(const double& radian);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Cos<long double>
    {
        long double operator ()(const long double& radian);
    };
}
}

#endif
