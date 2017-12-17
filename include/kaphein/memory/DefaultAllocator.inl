#ifndef KAPHEIN_MEMOTY_DEFAULTALLOCATOR_INL
#define KAPHEIN_MEMOTY_DEFAULTALLOCATOR_INL

#include <cstdlib>
#include "DefaultAllocator.hpp"

namespace kaphein
{
namespace memory
{
    template <typename T>
    T* DefaultAllocator<T>::allocate(SizeType n)
    {
        return static_cast<T*>(std::malloc(n * sizeof(T)));
    }

    template <typename T>
    void DefaultAllocator<T>::deallocate(T* p, SizeType n)
    {
        n;

        std::free(p);
    }

    template <typename T>
    bool operator ==(
        const DefaultAllocator<T>& lhs
        , const DefaultAllocator<T>& rhs
    )
    {
        lhs;
        rhs;

        return true;
    }

    template <typename T>
    bool operator !=(
        const DefaultAllocator<T>& lhs
        , const DefaultAllocator<T>& rhs
    )
    {
        return !(lhs == rhs);
    }
}
}

#endif
