#ifndef KAPHEIN_MATH_POW_HPP
#define KAPHEIN_MATH_POW_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "kaphein/cplusplus/UnsupportedMethodException.hpp"

namespace kaphein
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
    struct KAPHEIN_PP_DLL_API Pow<float>
    {
        float operator ()(const float& x, const float& y);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Pow<double>
    {
        double operator ()(const double& x, const double& y);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Pow<long double>
    {
        long double operator ()(const long double& x, const long double& y);
    };
}
}

#endif
