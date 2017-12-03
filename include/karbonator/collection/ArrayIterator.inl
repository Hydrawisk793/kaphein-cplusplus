#ifndef KARBONATOR_COLLECTION_ARRAYITERATOR_INL
#define KARBONATOR_COLLECTION_ARRAYITERATOR_INL

#include "ArrayIterator.hpp"

namespace karbonator
{
namespace collection
{
    template <typename E>
    ArrayIterator<E>::ArrayIterator()
        : ConstArrayIterator<E>()
    {}

    template <typename E>
    ArrayIterator<E>::ArrayIterator(const ArrayIterator<E> & src)
        : ConstArrayIterator<E>(src)
    {}

    template <typename E>
    ArrayIterator<E>::ArrayIterator(ArrayIterator<E> && src)
        : ConstArrayIterator<E>(std::move(src))
    {}

    template <typename E>
    ArrayIterator<E>::ArrayIterator(pointer pStart, pointer pEnd)
        : ConstArrayIterator<E>(pStart, pEnd)
    {}

    template <typename E>
    ArrayIterator<E>::ArrayIterator(pointer pStart, pointer pEnd, pointer pCurrent)
        : ConstArrayIterator<E>(pStat, pEnd, pCurrent)
    {}

    template <typename E>
    ArrayIterator<E>::~ArrayIterator()
    {}

    template <typename E>
    ArrayIterator<E> & ArrayIterator<E>::operator =(const ArrayIterator<E> & rhs)
    {
        ConstArrayIterator<E>::operator =(rhs);

        return *this;
    }

    template <typename E>
    ArrayIterator<E> & ArrayIterator<E>::operator =(ArrayIterator<E> && rhs)
    {
        ConstArrayIterator<E>::operator =(std::move(rhs));

        return *this;
    }
    
    template <typename E>
    typename ArrayIterator<E>::reference ArrayIterator<E>::operator *() const
    {
        return const_cast<reference>(ConstArrayIterator<E>::operator *());
    }

    template <typename E>
    typename ArrayIterator<E>::pointer ArrayIterator<E>::operator ->() const
    {
        return const_cast<pointer>(ConstArrayIterator<E>::operator ->());
    }

    template <typename E>
    typename ArrayIterator<E>::reference ArrayIterator<E>::operator [](
        difference_type diff
    ) const
    {
        return const_cast<reference>(ConstArrayIterator<E>::operator [](diff));
    }

    template <typename E>
    ArrayIterator<E> & ArrayIterator<E>::operator ++()
    {
        ConstArrayIterator<E>::operator ++();

        return *this;
    }

    template <typename E>
    ArrayIterator<E> ArrayIterator<E>::operator ++(int)
    {
        const ArrayIterator<E> previous(*this);

        ++(*this);

        return previous;
    }

    template <typename E>
    ArrayIterator<E> & ArrayIterator<E>::operator --()
    {
        ConstArrayIterator<E>::operator --();

        return *this;
    }

    template <typename E>
    ArrayIterator<E> ArrayIterator<E>::operator --(int)
    {
        const ArrayIterator<E> previous(*this);

        --(*this);

        return previous;
    }

    template <typename E>
    ArrayIterator<E> & ArrayIterator<E>::operator +=(
        difference_type diff
    )
    {
        ConstArrayIterator<E>::operator +=(diff);

        return *this;
    }

    template <typename E>
    ArrayIterator<E> & ArrayIterator<E>::operator -=(
        difference_type diff
    )
    {
        ConstArrayIterator<E>::operator -=(diff);

        return *this;
    }

    template <typename E>
    ArrayIterator<E> operator +(
        const ArrayIterator<E> & iter
        , typename ArrayIterator<E>::difference_type diff
    )
    {
        return ArrayIterator<E>(iter) += diff;
    }
    
    template <typename E>
    ArrayIterator<E> operator +(
        typename ArrayIterator<E>::difference_type diff
        , const ArrayIterator<E> & iter
    )
    {
        return (iter) + diff;
    }
            
    template <typename E>
    ArrayIterator<E> operator -(
        const ArrayIterator<E> & iter
        , typename ArrayIterator<E>::difference_type diff
    )
    { 
        return ArrayIterator<E>(iter) -= diff;
    }
}
}

#endif
