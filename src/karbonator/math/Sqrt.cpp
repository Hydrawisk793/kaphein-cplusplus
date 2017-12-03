#include <cmath>
#include "karbonator/math/Sqrt.hpp"

namespace karbonator
{
namespace math
{
    float Sqrt<float>::operator ()(const float& e)
    {
        return std::sqrt(e);
    }

    double Sqrt<double>::operator ()(const double& e)
    {
        return std::sqrt(e);
    }

    long double Sqrt<long double>::operator ()(const long double& e)
    {
        return std::sqrtl(e);
    }

    Int32 Sqrt<Int32>::operator ()(const Int32& e)
    {
        return static_cast<Int32>(Sqrt<double>()(e));
    }

    Int64 Sqrt<Int64>::operator ()(const Int64& e)
    {
        return static_cast<Int64>(Sqrt<long double>()(static_cast<long double>(e)));
    }
}
}
