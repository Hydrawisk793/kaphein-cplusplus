#ifndef KAPHEIN_UTILITY_ISVOLATILE_HPP
#define KAPHEIN_UTILITY_ISVOLATILE_HPP

#include "kaphein/pp/basic.hpp"

namespace kaphein
{
namespace utility
{
    template <typename T>
    struct IsVolatile
    {
    #if KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED > 0
        static constexpr bool value = false;
    #else
        static const bool value = false;
    #endif
    };

    template <typename T>
    struct IsVolatile<volatile T>
    {
    #if KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED > 0
        static constexpr bool value = true;
    #else
        static const bool value = true;
    #endif
    };
}
}

#endif
