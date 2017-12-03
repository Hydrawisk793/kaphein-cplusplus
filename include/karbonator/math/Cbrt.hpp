#ifndef KARBONATOR_MATH_CBRT_HPP
#define KARBONATOR_MATH_CBRT_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"
#include "Pow.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Cbrt
    {
        E operator ()(const E& v) {
            throw UnsupportedMethodException();
        }
    };
    
    template <>
    struct KARBONATOR_PP_DLL_API Cbrt<float>
    {
        float operator ()(const float& v);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Cbrt<double>
    {
        double operator ()(const double& v);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Cbrt<long double>
    {
        long double operator ()(const long double& v);
    };
}
}

#endif
