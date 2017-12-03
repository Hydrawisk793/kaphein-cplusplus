#include <cmath>
#include "karbonator/math/Atan.hpp"

namespace karbonator
{
namespace math
{
    float Atan<float>::operator ()(const float& value)
    {
        return std::atan(value);
    }

    double Atan<double>::operator ()(const double& value)
    {
        return std::atan(value);
    }

    long double Atan<long double>::operator ()(const long double& value)
    {
        return std::atan(value);
    }
}
}
