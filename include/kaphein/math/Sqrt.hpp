#ifndef KAPHEIN_MATH_SQRT_HPP
#define KAPHEIN_MATH_SQRT_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Sqrt
    {
        E operator ()(const E& e)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KAPHEIN_PP_DLL_API Sqrt<float>
    {
        float operator ()(const float& e);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Sqrt<double>
    {
        double operator ()(const double& e);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Sqrt<long double>
    {
        long double operator ()(const long double& e);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Sqrt<Int32>
    {
        Int32 operator ()(const Int32& e);
    };

    template <>
    struct KAPHEIN_PP_DLL_API Sqrt<Int64>
    {
        Int64 operator ()(const Int64& e);
    };
}
}

#endif
