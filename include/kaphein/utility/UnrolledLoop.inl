#ifndef KAPHEIN_UTILITY_UNROLLEDLOOP_INL
#define KAPHEIN_UTILITY_UNROLLEDLOOP_INL

#include "UnrolledLoop.inl"

namespace kaphein
{
namespace utility
{
    template <SizeType End, SizeType Start, SizeType Current>
    template <typename Callable>
    FORCEINLINE void UnrolledLoop<End, Start, Current>::step(Callable callable)
    {
        UnrolledLoop<End, Start, Current - 1>::step(callable);
        callable(Start + Current - 1);
    }
    
    template <SizeType End, SizeType Start>
    template <typename Callable>
    FORCEINLINE void UnrolledLoop<End, Start, 0>::step(Callable /*callable*/)
    {}
}
}

#endif
