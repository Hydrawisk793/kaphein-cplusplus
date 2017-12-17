#include <cmath>
#include "kaphein/math/Tan.hpp"

namespace kaphein
{
namespace math
{
    float Tan<float>::operator ()(const float& radian)
    {
        return std::tan(radian);
    }

    double Tan<double>::operator ()(const double& radian)
    {
        return std::tan(radian);
    }

    long double Tan<long double>::operator ()(const long double& radian)
    {
        return std::tan(radian);
    }
}
}
