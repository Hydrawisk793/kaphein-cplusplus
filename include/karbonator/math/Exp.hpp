#ifndef KARBONATOR_MATH_EXP_HPP
#define KARBONATOR_MATH_EXP_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Exp
    {
        E operator ()(const E& value) {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Exp<float>
    {
        float operator ()(const float& v);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Exp<double>
    {
        double operator ()(const double& v);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Exp<long double>
    {
        long double operator ()(const long double& v);
    };
}
}

#endif
