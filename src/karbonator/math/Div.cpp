/*
#include <cmath>
#include "karbonator/math/Epsilon.hpp"
#include "karbonator/math/Zero.hpp"
#include "karbonator/math/Equal.hpp"
#include "karbonator/math/Div.hpp"

namespace karbonator
{
namespace math
{
    bool Div<int>::operator ()(
        const int & numerator
        , const int & denominator
        , int & quotientOut
        , int & reminderOut
    )
    {
        const bool result = Equal<int>()(denominator, Zero<int>(), Epsilon<int>());
        if(result)
        {
            std::div_t values = std::div(numerator, denominator);
            quotientOut = values.quot;
            reminderOut = values.rem;
        }

        return result;
    }

    bool Div<long>::operator ()(
        const long & numerator
        , const long & denominator
        , long & quotientOut
        , long & reminderOut
    )
    {
        const bool result = Equal<long>()(denominator, Zero<long>(), Epsilon<long>());
        if(result)
        {
            std::ldiv_t values = std::ldiv(numerator, denominator);
            quotientOut = values.quot;
            reminderOut = values.rem;
        }

        return result;
    }

    bool Div<long long>::operator ()(
        const long long & numerator
        , const long long & denominator
        , long long & quotientOut
        , long long & reminderOut
    )
    {
        const bool result = Equal<long long>()(denominator, Zero<long long>(), Epsilon<long long>());
        if(result)
        {
            std::lldiv_t values = std::lldiv(numerator, denominator);
            quotientOut = values.quot;
            reminderOut = values.rem;
        }

        return result;
    }
}
}
*/