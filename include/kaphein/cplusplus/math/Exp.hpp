#ifndef KAPHEIN_MATH_EXP_HPP
#define KAPHEIN_MATH_EXP_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "kaphein/cplusplus/UnsupportedMethodException.hpp"

namespace kaphein
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
    struct KAPHEIN_PP_DLL_API Exp<float>
    {
        float operator ()(const float& v);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Exp<double>
    {
        double operator ()(const double& v);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Exp<long double>
    {
        long double operator ()(const long double& v);
    };
}
}

#endif
