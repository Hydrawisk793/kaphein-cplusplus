#ifndef KAPHEIN_MATH_COS_HPP
#define KAPHEIN_MATH_COS_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
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
    struct KAPHEIN_PP_DLL_API Cos<float>
    {
        float operator ()(const float& radian);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Cos<double>
    {
        double operator ()(const double& radian);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Cos<long double>
    {
        long double operator ()(const long double& radian);
    };
}
}

#endif
