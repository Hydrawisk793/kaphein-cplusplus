#ifndef KARBONATOR_TMP_UNROLLEDLOOP_INL
#define KARBONATOR_TMP_UNROLLEDLOOP_INL

#include "UnrolledLoop.inl"

namespace karbonator
{
namespace utility
{
    template <SizeType StepCount>
    template <typename Callable>
    FORCEINLINE void UnrolledLoop<StepCount>::step(Callable callable)
    {
        UnrolledLoop<StepCount - 1>::step(callable);
        callable(StepCount - 1);
    }

    template <typename Callable>
    FORCEINLINE void UnrolledLoop<0>::step(Callable /*callable*/)
    {}
}
}

#endif
