#ifndef KARBONATOR_COLLECTION_VECTOR_HPP
#define KARBONATOR_COLLECTION_VECTOR_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/memory/DefaultAllocator.hpp"
#include "karbonator/collection/ArrayIterator.hpp"

namespace karbonator
{
namespace collection
{
    /**
     * @brief A linear collection.
     */
    template <
        typename E,
        typename A = memory::DefaultAllocator<E>
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

        typedef ConstArrayIterator<E> const_iterator;

        typedef ArrayIterator<E> iterator;

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

    public:
        //Vector<E, A>& set(const_iterator iter, const E& e);

        //Vector<E, A>& set(const_iterator iter, E&& e);

        Vector<E, A>& swapElements(iterator lhs, iterator rhs);

        //Vector<E, A>& insert(const_iterator iter, const E& e);

        //Vector<E, A>& insert(const_iterator iter, E&& e);

        //template <typename Iter>
        //Vector<E, A>& insert(const_iterator iter, Iter beginIter, Iter endIter);

        //Vector<E, A>& remove(const_iterator iter);

        //Vector<E, A>& remove(const_iterator beginIter, const_iterator endIter);

        Vector<E, A>& clear();

        //Vector<E, A>& pushFront(const E& e);

        //Vector<E, A>& pushFront(E&& e);

        //E popFront();

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

    public:
        E* pStart_;

        E* pEnd_;

        E* pTop_;

        A allocator_;
    };
}
}

#include "karbonator/collection/Vector.inl"

#endif
