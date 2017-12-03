#ifndef KARBONATOR_MATH_SQRT_HPP
#define KARBONATOR_MATH_SQRT_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
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
    struct KARBONATOR_PP_DLL_API Sqrt<float>
    {
        float operator ()(const float& e);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sqrt<double>
    {
        double operator ()(const double& e);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sqrt<long double>
    {
        long double operator ()(const long double& e);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sqrt<Int32>
    {
        Int32 operator ()(const Int32& e);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Sqrt<Int64>
    {
        Int64 operator ()(const Int64& e);
    };
}
}

#endif
