#ifndef KARBONATOR_MEMOTY_DEFAULTALLOCATOR_HPP
#define KARBONATOR_MEMOTY_DEFAULTALLOCATOR_HPP

namespace karbonator
{
namespace memory
{
    template <typename T>
    struct DefaultAllocator
    {
        typedef T value_type;

        T* allocate(SizeType n);

        void deallocate(T* p, SizeType n);
    };
}
}

#include "DefaultAllocator.inl"

#endif
