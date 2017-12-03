#ifndef KARBONATOR_COLLECTION_CONSTARRAYITERATOR_HPP
#define KARBONATOR_COLLECTION_CONSTARRAYITERATOR_HPP

#include <iterator>
#include "karbonator/pp/basic.hpp"
#include "ConstArrayIteratorBase.hpp"

namespace karbonator
{
namespace collection
{
    /**
     * @brief A generic array const iterator.
     */
    template <typename E>
    class ConstArrayIterator
        : public ConstArrayIteratorBase
    {
    public:
        typedef const E value_type;

        typedef const E& reference;

        typedef const E * pointer;

        typedef PtrDiff difference_type;

        typedef std::random_access_iterator_tag iterator_category;

    public:
        ConstArrayIterator();

        ConstArrayIterator(const ConstArrayIterator<E>& source);

        ConstArrayIterator(ConstArrayIterator<E>&& source);
        
        ConstArrayIterator(pointer pStart, pointer pEnd);

        ConstArrayIterator(pointer pStart, pointer pEnd, pointer pCurrent);

        virtual ~ConstArrayIterator();

        ConstArrayIterator<E>& operator =(const ConstArrayIterator<E>& rhs);

        ConstArrayIterator<E>& operator =(ConstArrayIterator<E>&& rhs);

    public:
        reference operator *() const;
        
        pointer operator ->() const;

        reference operator [](difference_type diff) const;

    public:
        ConstArrayIterator<E>& operator ++();

        ConstArrayIterator<E> operator ++(int);

        ConstArrayIterator<E>& operator --();

        ConstArrayIterator<E> operator --(int);

        ConstArrayIterator<E>& operator +=(difference_type diff);

        ConstArrayIterator<E>& operator -=(difference_type diff);

        template <typename E>
        friend ConstArrayIterator<E> operator +(
            const ConstArrayIterator<E>& iter,
            typename ConstArrayIterator<E>::difference_type diff
        );
        
        template <typename E>
        friend ConstArrayIterator<E> operator +(
            typename ConstArrayIterator<E>::difference_type diff,
            const ConstArrayIterator<E> & iter
        );
        
        template <typename E>
        friend ConstArrayIterator<E> operator -(
            const ConstArrayIterator<E>& iter,
            typename ConstArrayIterator<E>::difference_type diff
        );

        difference_type operator -(const ConstArrayIterator<E> & rhs) const;

    public:
        bool operator ==(const ConstArrayIterator<E>& rhs) const;

        bool operator !=(const ConstArrayIterator<E>& rhs) const;

        bool operator <(const ConstArrayIterator<E>& rhs) const;

        bool operator >=(const ConstArrayIterator<E>& rhs) const;

        bool operator <=(const ConstArrayIterator<E>& rhs) const;

        bool operator >(const ConstArrayIterator<E>& rhs) const;
    };
}
}

#include "ConstArrayIterator.inl"

#endif
