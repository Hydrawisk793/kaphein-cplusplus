#include <cmath>
#include "karbonator/math/Cos.hpp"

namespace karbonator
{
namespace math
{
    float Cos<float>::operator ()(const float& radian)
    {
        return std::cos(radian);
    }

    double Cos<double>::operator ()(const double& radian)
    {
        return std::cos(radian);
    }

    long double Cos<long double>::operator ()(const long double& radian)
    {
        return std::cos(radian);
    }
}
}
