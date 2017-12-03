#ifndef KARBONATOR_MATH_ASIN_HPP
#define KARBONATOR_MATH_ASIN_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Asin
    {
        E operator ()(const E& value) {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct KARBONATOR_PP_DLL_API Asin<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Asin<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct KARBONATOR_PP_DLL_API Asin<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
