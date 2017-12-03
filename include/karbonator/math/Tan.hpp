#ifndef KARBONATOR_MATH_TAN_HPP
#define KARBONATOR_MATH_TAN_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Tan
    {
        E operator ()(const E& radian)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Tan<float>
    {
        float operator ()(const float& radian);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Tan<double>
    {
        double operator ()(const double& radian);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Tan<long double>
    {
        long double operator ()(const long double& radian);
    };
}
}

#endif
