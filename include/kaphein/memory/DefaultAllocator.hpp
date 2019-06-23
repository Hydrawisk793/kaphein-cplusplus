#ifndef KAPHEIN_MEMOTY_DEFAULTALLOCATOR_HPP
#define KAPHEIN_MEMOTY_DEFAULTALLOCATOR_HPP

namespace kaphein
{
    namespace memory
    {
        /**
         *  @since 2014-03-23
         */
        template <typename T>
        struct DefaultAllocator
        {
            typedef T value_type;

            T * allocate(
                SizeType n
            );

            void deallocate(
                T * p
                , SizeType n
            );

            template <typename T>
            friend bool operator ==(
                const DefaultAllocator<T>& lhs
                , const DefaultAllocator<T>& rhs
            );

            template <typename T>
            friend bool operator !=(
                const DefaultAllocator<T>& lhs
                , const DefaultAllocator<T>& rhs
            );
        };
    }
}

#include "DefaultAllocator.inl"

#endif
