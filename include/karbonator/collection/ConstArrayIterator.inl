#ifndef KARBONATOR_COLLECTION_CONSTARRAYITERATOR_INL
#define KARBONATOR_COLLECTION_CONSTARRAYITERATOR_INL

#include <utility>
#include "ConstArrayIterator.hpp"

namespace karbonator
{
namespace collection
{
    template <typename E>
    ConstArrayIterator<E>::ConstArrayIterator()
        : ConstArrayIteratorBase()
    {}

    template <typename E>
    ConstArrayIterator<E>::ConstArrayIterator(const ConstArrayIterator<E>& src)
        : ConstArrayIteratorBase(src)
    {}

    template <typename E>
    ConstArrayIterator<E>::ConstArrayIterator(ConstArrayIterator<E>&& source)
        : ConstArrayIteratorBase(std::move(src))
    {}

    template <typename E>
    ConstArrayIterator<E>::ConstArrayIterator(pointer pStart, pointer pEnd)
        : ConstArrayIteratorBase(pStart, pEnd)
    {}

    template <typename E>
    ConstArrayIterator<E>::ConstArrayIterator(pointer pStart, pointer pEnd, pointer pCurrent)
        : ConstArrayIteratorBase(pStart, pEnd, pCurrent)
    {}

    template <typename E>
    ConstArrayIterator<E>::~ConstArrayIterator() {}
    
    template <typename E>
    ConstArrayIterator<E>& ConstArrayIterator<E>::operator =(const ConstArrayIterator<E>& rhs)
    {
        ConstArrayIteratorBase::operator =(rhs);
        
        return *this;
    }
    
    template <typename E>
    ConstArrayIterator<E>& ConstArrayIterator<E>::operator =(ConstArrayIterator<E>&& rhs)
    {
        ConstArrayIteratorBase::operator =(std::move(rhs));
        
        return *this;
    }

    template <typename E>
    typename ConstArrayIterator<E>::reference ConstArrayIterator<E>::operator *() const
    {
        return *static_cast<pointer>(static_cast<const void*>(getCurrent()));
    }
    
    template <typename E>
    typename ConstArrayIterator<E>::pointer ConstArrayIterator<E>::operator ->() const
    {
        return static_cast<pointer>(static_cast<const void*>(getCurrent()));
    }

    template <typename E>
    typename ConstArrayIterator<E>::reference ConstArrayIterator<E>::operator [](difference_type diff) const
    {
        return static_cast<pointer>(static_cast<const void*>(getCurrent()))[diff];
    }

    template <typename E>
    ConstArrayIterator<E>& ConstArrayIterator<E>::operator ++() {
        //++pCurrent_;
        moveToNext(sizeof(E));

        return *this;
    }

    template <typename E>
    ConstArrayIterator<E> ConstArrayIterator<E>::operator ++(int) {
        const ConstArrayIterator<E> previous(*this);

        ++(*this);

        return previous;
    }

    template <typename E>
    ConstArrayIterator<E>& ConstArrayIterator<E>::operator --() {
        //--pCurrent_;
        moveToPrevious(sizeof(E));

        return *this;
    }

    template <typename E>
    ConstArrayIterator<E> ConstArrayIterator<E>::operator --(int) {
        const ConstArrayIterator<E> previous(*this);

        --(*this);

        return previous;
    }
    
    template <typename E>
    ConstArrayIterator<E>& ConstArrayIterator<E>::operator +=(difference_type diff) {
        //pCurrent_ += diff;
        moveToNext(sizeof(E), diff);
        
        return *this;
    }

    template <typename E>
    ConstArrayIterator<E>& ConstArrayIterator<E>::operator -=(difference_type diff) {
        //pCurrent_ -= diff;
        moveToPrevious(sizeof(E), diff);
        
        return *this;
    }

    template <typename E>
    ConstArrayIterator<E> operator +(
        const ConstArrayIterator<E>& iter,
        typename ConstArrayIterator<E>::difference_type diff
    ) {
        return ConstArrayIterator<E>(*this) += diff;
    }
    
    template <typename E>
    ConstArrayIterator<E> operator +(
        typename ConstArrayIterator<E>::difference_type diff,
        const ConstArrayIterator<E>& iter
    ) {
        return (*this) + diff;
    }
    
    template <typename E>
    ConstArrayIterator<E> operator -(
        const ConstArrayIterator<E>& iter,
        typename ConstArrayIterator<E>::difference_type diff
    ) {
        return ConstArrayIterator<E>(*this) -= diff;
    }

    template <typename E>
    typename ConstArrayIterator<E>::difference_type ConstArrayIterator<E>::operator -(const ConstArrayIterator<E>& rhs) const
    {
        return getDifference(rhs);
    }

    template <typename E>
    bool ConstArrayIterator<E>::operator ==(const ConstArrayIterator<E>& rhs) const
    {
        return equals(rhs);
    }
    
    template <typename E>
    bool ConstArrayIterator<E>::operator !=(const ConstArrayIterator<E>& rhs) const
    {
        return !((*this) == rhs);
    }
    
    template <typename E>
    bool ConstArrayIterator<E>::operator <(const ConstArrayIterator<E>& rhs) const
    {
        return lessThan(rhs);
    }
    
    template <typename E>
    bool ConstArrayIterator<E>::operator >=(const ConstArrayIterator<E>& rhs) const 
    {
        return !((*this) < rhs);
    }
    
    template <typename E>
    bool ConstArrayIterator<E>::operator <=(const ConstArrayIterator<E>& rhs) const
    {
        return lessThanOrEqualTo(rhs);
    }

    template <typename E>
    bool ConstArrayIterator<E>::operator >(const ConstArrayIterator<E>& rhs) const
    {
        return !((*this) <= rhs);
    }
}
}

#endif
