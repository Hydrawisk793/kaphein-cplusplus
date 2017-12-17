#ifndef KAPHEIN_UTILITY_UNROLLEDLOOP_HPP
#define KAPHEIN_UTILITY_UNROLLEDLOOP_HPP

#include "kaphein/cplusplus/pp/basic.hpp"

namespace kaphein
{
namespace utility
{
    template <
        SizeType End
        , SizeType Start = 0
        , SizeType Current = End - Start
    >
    struct UnrolledLoop
    {
        template <typename Callable>
        static void step(Callable callable);
    };

    template <
        SizeType End
        , SizeType Start
    >
    struct UnrolledLoop<End, Start, 0>
    {
        template <typename Callable>
        static void step(Callable callable);
    };
}
}

#include "UnrolledLoop.inl"

#endif
