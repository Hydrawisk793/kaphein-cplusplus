#ifndef KAPHEIN_COLLECTION_ARRAYITERATOR_HPP
#define KAPHEIN_COLLECTION_ARRAYITERATOR_HPP

#include <iterator>
#include "kaphein/utility/SelectType.hpp"
#include "kaphein/pp/basic.hpp"
#include "ArrayIteratorBase.hpp"

namespace kaphein
{
namespace collection
{
    /**
     *  @brief A generic array iterator class template.
     *  @since 2014-03-23
     */
    template <
        typename E
        , bool IsConstIterator
    >
    class ArrayIterator
        : public ArrayIteratorBase
    {
    private:
        typedef typename utility::SelectType<IsConstIterator, const void*, void*>::SelectedType VoidPtrType;

    public:
        typedef typename utility::SelectType<IsConstIterator, const E, E>::SelectedType value_type;

        typedef typename utility::SelectType<IsConstIterator, const E*, E*>::SelectedType pointer;

        typedef typename utility::SelectType<IsConstIterator, const E&, E&>::SelectedType reference;

        typedef ArrayIteratorBase::difference_type difference_type;

        typedef std::random_access_iterator_tag iterator_category;

    public:
        ArrayIterator();

        ArrayIterator(const ArrayIterator<E, IsConstIterator>& source);

        ArrayIterator(ArrayIterator<E, IsConstIterator>&& source);
        
        ArrayIterator(pointer pStart, pointer pEnd);

        ArrayIterator(pointer pStart, pointer pEnd, pointer pCurrent);

        virtual ~ArrayIterator();

        ArrayIterator<E, IsConstIterator>& operator =(const ArrayIterator<E, IsConstIterator>& rhs);

        ArrayIterator<E, IsConstIterator>& operator =(ArrayIterator<E, IsConstIterator>&& rhs);

    public:
        reference operator *() const;
        
        pointer operator ->() const;

        reference operator [](difference_type diff) const;

    public:
        ArrayIterator<E, IsConstIterator>& operator ++();

        ArrayIterator<E, IsConstIterator> operator ++(int);

        ArrayIterator<E, IsConstIterator>& operator --();

        ArrayIterator<E, IsConstIterator> operator --(int);

        ArrayIterator<E, IsConstIterator>& operator +=(difference_type diff);

        template <typename E, bool IsConstIterator>
        friend ArrayIterator<E, IsConstIterator> operator +(
            const ArrayIterator<E, IsConstIterator>& iter
            , typename ArrayIterator<E, IsConstIterator>::difference_type diff
        );
        
        template <typename E, bool IsConstIterator>
        friend ArrayIterator<E, IsConstIterator> operator +(
            typename ArrayIterator<E, IsConstIterator>::difference_type diff
            , const ArrayIterator<E, IsConstIterator> & iter
        );

        ArrayIterator<E, IsConstIterator>& operator -=(difference_type diff);
        
        template <typename E, bool IsConstIterator>
        friend ArrayIterator<E, IsConstIterator> operator -(
            const ArrayIterator<E, IsConstIterator>& iter
            , typename ArrayIterator<E, IsConstIterator>::difference_type diff
        );

        difference_type operator -(const ArrayIterator<E, IsConstIterator> & rhs) const;

    public:
        bool operator ==(const ArrayIterator<E, IsConstIterator>& rhs) const;

        bool operator !=(const ArrayIterator<E, IsConstIterator>& rhs) const;

        bool operator <(const ArrayIterator<E, IsConstIterator>& rhs) const;

        bool operator >=(const ArrayIterator<E, IsConstIterator>& rhs) const;

        bool operator <=(const ArrayIterator<E, IsConstIterator>& rhs) const;

        bool operator >(const ArrayIterator<E, IsConstIterator>& rhs) const;
    };
}
}

#include "ArrayIterator.inl"

#endif
