#ifndef KAPHEIN_COLLECTION_ARRAYITERATOR_INL
#define KAPHEIN_COLLECTION_ARRAYITERATOR_INL

#include <utility>
#include "ArrayIterator.hpp"

namespace kaphein
{
namespace collection
{
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>::ArrayIterator()
        : ArrayIteratorBase()
    {}

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>::ArrayIterator(const ArrayIterator<E, IsConstIterator>& src)
        : ArrayIteratorBase(src)
    {}

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>::ArrayIterator(ArrayIterator<E, IsConstIterator>&& src)
        : ArrayIteratorBase(std::move(src))
    {}

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>::ArrayIterator(pointer pStart, pointer pEnd)
        : ArrayIteratorBase(pStart, pEnd)
    {}

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>::ArrayIterator(pointer pStart, pointer pEnd, pointer pCurrent)
        : ArrayIteratorBase(pStart, pEnd, pCurrent)
    {}

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>::~ArrayIterator() {}
    
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>& ArrayIterator<E, IsConstIterator>::operator =(const ArrayIterator<E, IsConstIterator>& rhs)
    {
        ArrayIteratorBase::operator =(rhs);
        
        return *this;
    }
    
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>& ArrayIterator<E, IsConstIterator>::operator =(ArrayIterator<E, IsConstIterator>&& rhs)
    {
        ArrayIteratorBase::operator =(std::move(rhs));
        
        return *this;
    }

    template <typename E, bool IsConstIterator>
    typename ArrayIterator<E, IsConstIterator>::reference ArrayIterator<E, IsConstIterator>::operator *() const
    {
        return *static_cast<pointer>(const_cast<VoidPtrType>(getCurrent()));
    }
    
    template <typename E, bool IsConstIterator>
    typename ArrayIterator<E, IsConstIterator>::pointer ArrayIterator<E, IsConstIterator>::operator ->() const
    {
        return static_cast<pointer>(const_cast<VoidPtrType>(getCurrent()));
    }

    template <typename E, bool IsConstIterator>
    typename ArrayIterator<E, IsConstIterator>::reference ArrayIterator<E, IsConstIterator>::operator [](difference_type diff) const
    {
        return static_cast<pointer>(const_cast<VoidPtrType>(getCurrent()))[diff];
    }

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>& ArrayIterator<E, IsConstIterator>::operator ++() {
        //++pCurrent_;
        moveToNext(sizeof(E));

        return *this;
    }

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator> ArrayIterator<E, IsConstIterator>::operator ++(int) {
        const ArrayIterator<E, IsConstIterator> previous(*this);

        ++(*this);

        return previous;
    }

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>& ArrayIterator<E, IsConstIterator>::operator --() {
        //--pCurrent_;
        moveToPrevious(sizeof(E));

        return *this;
    }

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator> ArrayIterator<E, IsConstIterator>::operator --(int) {
        const ArrayIterator<E, IsConstIterator> previous(*this);

        --(*this);

        return previous;
    }
    
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>& ArrayIterator<E, IsConstIterator>::operator +=(difference_type diff) {
        //pCurrent_ += diff;
        moveToNext(sizeof(E), diff);
        
        return *this;
    }

    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator> operator +(
        const ArrayIterator<E, IsConstIterator>& iter,
        typename ArrayIterator<E, IsConstIterator>::difference_type diff
    ) {
        return ArrayIterator<E, IsConstIterator>(iter) += diff;
    }
    
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator> operator +(
        typename ArrayIterator<E, IsConstIterator>::difference_type diff,
        const ArrayIterator<E, IsConstIterator>& iter
    ) {
        return iter + diff;
    }
    
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator> operator -(
        const ArrayIterator<E, IsConstIterator>& iter,
        typename ArrayIterator<E, IsConstIterator>::difference_type diff
    ) {
        return ArrayIterator<E, IsConstIterator>(iter) -= diff;
    }
    
    template <typename E, bool IsConstIterator>
    ArrayIterator<E, IsConstIterator>& ArrayIterator<E, IsConstIterator>::operator -=(difference_type diff) {
        //pCurrent_ -= diff;
        moveToPrevious(sizeof(E), diff);
        
        return *this;
    }

    template <typename E, bool IsConstIterator>
    typename ArrayIterator<E, IsConstIterator>::difference_type ArrayIterator<E, IsConstIterator>::operator -(const ArrayIterator<E, IsConstIterator>& rhs) const
    {
        return getDifference(rhs);
    }

    template <typename E, bool IsConstIterator>
    bool ArrayIterator<E, IsConstIterator>::operator ==(const ArrayIterator<E, IsConstIterator>& rhs) const
    {
        return equals(rhs);
    }
    
    template <typename E, bool IsConstIterator>
    bool ArrayIterator<E, IsConstIterator>::operator !=(const ArrayIterator<E, IsConstIterator>& rhs) const
    {
        return !((*this) == rhs);
    }
    
    template <typename E, bool IsConstIterator>
    bool ArrayIterator<E, IsConstIterator>::operator <(const ArrayIterator<E, IsConstIterator>& rhs) const
    {
        return lessThan(rhs);
    }
    
    template <typename E, bool IsConstIterator>
    bool ArrayIterator<E, IsConstIterator>::operator >=(const ArrayIterator<E, IsConstIterator>& rhs) const 
    {
        return !((*this) < rhs);
    }
    
    template <typename E, bool IsConstIterator>
    bool ArrayIterator<E, IsConstIterator>::operator <=(const ArrayIterator<E, IsConstIterator>& rhs) const
    {
        return lessThanOrEqualTo(rhs);
    }

    template <typename E, bool IsConstIterator>
    bool ArrayIterator<E, IsConstIterator>::operator >(const ArrayIterator<E, IsConstIterator>& rhs) const
    {
        return !((*this) <= rhs);
    }
}
}

#endif
