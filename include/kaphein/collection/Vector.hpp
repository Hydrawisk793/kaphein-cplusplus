#ifndef KAPHEIN_COLLECTION_VECTOR_HPP
#define KAPHEIN_COLLECTION_VECTOR_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/memory/DefaultAllocator.hpp"
#include "kaphein/collection/ArrayIterator.hpp"

namespace kaphein
{
    namespace collection
    {
        /**
         *  @brief A linear collection.
         *  @since 2014-03-23
         */
        template <
            typename E
            , typename A = memory::DefaultAllocator<E>
        >
        class Vector
        {
        public:
            enum
            {
                defaultCapacity = 8
            };
        
        public:
            typedef E ElementType;

            typedef A AllocatorType;

            typedef ArrayIterator<E, true> const_iterator;

            typedef ArrayIterator<E, false> iterator;

            typedef E value_type;

            typedef const E& const_reference;

        public:
            Vector(A allocator = A());

            Vector(const Vector<E, A>& src);

            Vector(Vector<E, A>&& src);

            Vector(SizeType elementCount, const E& e = E(), A allocator = A());

            Vector(const E* pElements, SizeType elementCount, A allocator = A());

            Vector(E*&& pAllocatedElements, SizeType elementCount, A allocator = A());

            virtual ~Vector();

            Vector<E, A>& operator =(const Vector<E, A>& rhs);

            Vector<E, A>& operator =(Vector<E, A>&& rhs);

        public:
            const_iterator cbegin() const;

            const_iterator cend() const;

            const_iterator begin() const;

            iterator begin();

            const_iterator end() const;

            iterator end();

        public:
            bool isEmpty() const;

            SizeType getElementCount() const;

            SizeType getCapacity() const;

            Vector<E, A>& reserve(SizeType size);

            Vector<E, A>& resize(SizeType size);
        
            Vector<E, A>& resize(SizeType size, const E& e);

            Vector<E, A>& trim();

        public:
            const E& operator [](SizeType index) const;

            E& operator [](SizeType index);

            const E& at(SizeType index) const;

            E& at(SizeType index);

            const E* getElementPointer() const;

            E* getElementPointer();

            void swap(Vector<E, A>& rhs);

        public:
            Vector<E, A>& emplace(const_iterator iter, E&& e);

            Vector<E, A>& swapElements(iterator lhs, iterator rhs);

            Vector<E, A>& insert(const_iterator pos, const E& e);

            Vector<E, A>& insert(const_iterator pos, E&& e);

            //Vector<E, A>& insert(const_iterator pos, SizeType count, const E& e);

            //template <typename Iter>
            //Vector<E, A>& insert(const_iterator pos, Iter srcBegin, Iter srcEnd);

            Vector<E, A>& remove(const_iterator pos);

            //Vector<E, A>& remove(const_iterator destBegin, const_iterator destEnd);

            Vector<E, A>& clear();

            Vector<E, A>& pushFront(const E& e);

            Vector<E, A>& pushFront(E&& e);

            E popFront();

            Vector<E, A>& pushBack(const E& e);

            Vector<E, A>& pushBack(E&& e);

            E popBack();

        public:
            bool lessThan(const Vector<E, A>& rhs) const;

            template <typename E, typename A>
            friend bool operator ==(const Vector<E, A>& lhs, const Vector<E, A>& rhs);

            template <typename E, typename A>
            friend bool operator !=(const Vector<E, A>& lhs, const Vector<E, A>& rhs);

            template <typename E, typename A>
            friend bool operator <(const Vector<E, A>& lhs, const Vector<E, A>& rhs);
        
            template <typename E, typename A>
            friend bool operator >=(const Vector<E, A>& lhs, const Vector<E, A>& rhs);
        
            template <typename E, typename A>
            friend bool operator <=(const Vector<E, A>& lhs, const Vector<E, A>& rhs);

            template <typename E, typename A>
            friend bool operator >(const Vector<E, A>& lhs, const Vector<E, A>& rhs);

        private:
            E* constructContainer(SizeType capacity);

            void reconstructContainer(SizeType size);

            void expandIfFull(SizeType n);

            bool resizeByReducing(SizeType size);

            void shiftElementsToLeft(E* pBegin, E* pEnd);

            void shiftElementsToRight(E* pBegin, E* pEnd);

            void invalidateSelf();

        private:
            void assertIndexInRange(SizeType index) const;

            void assertInElementRange(E* pBegin, E* pEnd) const;

            void assertIsNotEmpty() const;

            void assertPointerInElements(const E* p) const;

        public:
            E* pStart_;

            E* pEnd_;

            E* pTop_;

            A allocator_;
        };
    }
}

#include "Vector.inl"

#endif
