#ifndef KAPHEIN_MATH_CBRT_HPP
#define KAPHEIN_MATH_CBRT_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"
#include "Pow.hpp"

namespace kaphein
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
    struct KAPHEIN_PP_DLL_API Cbrt<float>
    {
        float operator ()(const float& v);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Cbrt<double>
    {
        double operator ()(const double& v);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Cbrt<long double>
    {
        long double operator ()(const long double& v);
    };
}
}

#endif
