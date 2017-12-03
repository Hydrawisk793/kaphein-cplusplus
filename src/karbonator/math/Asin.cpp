#include <cmath>
#include "karbonator/math/Asin.hpp"

namespace karbonator
{
namespace math
{
    float Asin<float>::operator ()(const float& value)
    {
        return std::asin(value);
    }

    double Asin<double>::operator ()(const double& value)
    {
        return std::asin(value);
    }

    long double Asin<long double>::operator ()(const long double& value)
    {
        return std::asin(value);
    }
}
}
