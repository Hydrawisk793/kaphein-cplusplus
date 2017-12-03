#ifndef KARBONATOR_MATH_ACOS_HPP
#define KARBONATOR_MATH_ACOS_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Acos
    {
        E operator ()(const E& value)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Acos<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Acos<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Acos<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
