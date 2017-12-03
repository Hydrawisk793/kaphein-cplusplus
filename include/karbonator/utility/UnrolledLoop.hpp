#ifndef KARBONATOR_TMP_UNROLLEDLOOP_HPP
#define KARBONATOR_TMP_UNROLLEDLOOP_HPP

#include "karbonator/pp/basic.hpp"

namespace karbonator
{
namespace utility
{
    template <SizeType StepCount>
    struct UnrolledLoop
    {
        template <typename Callable>
        static void step(Callable callable);
    };

    template <>
    struct UnrolledLoop<0>
    {
        template <typename Callable>
        static void step(Callable callable);
    };
}
}

#include "UnrolledLoop.inl"

#endif
