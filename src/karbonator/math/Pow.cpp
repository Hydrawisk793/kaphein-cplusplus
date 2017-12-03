#include <cmath>
#include "karbonator/math/Pow.hpp"

namespace karbonator
{
namespace math
{
    float Pow<float>::operator ()(const float& x, const float& y)
    {
        return std::pow(x, y);
    }

    double Pow<double>::operator ()(const double& x, const double& y)
    {
        return std::pow(x, y);
    }

    long double Pow<long double>::operator ()(const long double& x, const long double& y)
    {
        return std::pow(x, y);
    }
}
}