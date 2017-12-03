#include "karbonator/math/Pow.hpp"
#include "karbonator/math/Cbrt.hpp"

namespace karbonator
{
namespace math
{
    float Cbrt<float>::operator ()(const float& v)
    {
        return Pow<float>()(v, 1.0f / 3.0f);
    }

    double Cbrt<double>::operator ()(const double& v)
    {
        return Pow<double>()(v, 1.0 / 3.0);
    }

    long double Cbrt<long double>::operator ()(const long double& v)
    {
        return Pow<long double>()(v, 1.0l / 3.0l);
    }
}
}
