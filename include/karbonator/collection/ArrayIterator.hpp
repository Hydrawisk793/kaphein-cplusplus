#ifndef KARBONATOR_COLLECTION_ARRAYITERATOR_HPP
#define KARBONATOR_COLLECTION_ARRAYITERATOR_HPP

#include "ConstArrayIterator.hpp"

namespace karbonator
{
namespace collection
{
    template <typename E>
    class ArrayIterator
        : public ConstArrayIterator<E>
    {
    public:
        typedef E value_type;

        typedef E& reference;

        typedef E* pointer;

    public:
        ArrayIterator();

        ArrayIterator(const ArrayIterator<E>& src);

        ArrayIterator(ArrayIterator<E>&& src);

        ArrayIterator(pointer pStart, pointer pEnd);

        ArrayIterator(pointer pStart, pointer pEnd, pointer pCurrent);

        virtual ~ArrayIterator();

        ArrayIterator<E>& operator =(const ArrayIterator<E>& rhs);

        ArrayIterator<E>& operator =(ArrayIterator<E>&& rhs);

    public:
        reference operator *() const;
        
        pointer operator ->() const;

        reference operator [](difference_type diff) const;

    public:
        ArrayIterator<E>& operator ++();

        ArrayIterator<E> operator ++(int);

        ArrayIterator<E>& operator --();

        ArrayIterator<E> operator --(int);

        ArrayIterator<E>& operator +=(difference_type diff);

        ArrayIterator<E>& operator -=(difference_type diff);

        template <typename E>
        friend ArrayIterator<E> operator +(
            const ArrayIterator<E>& iter
            , typename ArrayIterator<E>::difference_type diff
        );
        
        template <typename E>
        friend ArrayIterator<E> operator +(
            typename ArrayIterator<E>::difference_type diff
            , const ArrayIterator<E>& iter
        );
        
        template <typename E>
        friend ArrayIterator<E> operator -(
            const ArrayIterator<E>& iter
            , typename ArrayIterator<E>::difference_type diff
        );
    };
}
}

#include "ArrayIterator.inl"

#endif
