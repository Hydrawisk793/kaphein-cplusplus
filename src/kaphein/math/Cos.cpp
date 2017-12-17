#include <cmath>
#include "kaphein/math/Cos.hpp"

namespace kaphein
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
