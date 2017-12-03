#ifndef KARBONATOR_MATH_ATAN2_HPP
#define KARBONATOR_MATH_ATAN2_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Atan2
    {
        E operator ()(const E& y, const E& x)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Atan2<float>
    {
        float operator ()(const float& y, const float& x);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Atan2<double>
    {
        double operator ()(const double& y, const double& x);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Atan2<long double>
    {
        long double operator ()(const long double& y, const long double& x);
    };
}
}

#endif
