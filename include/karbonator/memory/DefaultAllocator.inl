#ifndef KARBONATOR_MEMOTY_DEFAULTALLOCATOR_INL
#define KARBONATOR_MEMOTY_DEFAULTALLOCATOR_INL

#include <cstdlib>
#include "DefaultAllocator.hpp"

namespace karbonator
{
namespace memory
{
    template <typename T>
    T* DefaultAllocator<T>::allocate(SizeType n)
    {
        return (T*)std::malloc(sizeof(T) * n);
    }

    template <typename T>
    void DefaultAllocator<T>::deallocate(T* p, SizeType n)
    {
        n;

        std::free(p);
    }
}
}

#endif
