#ifndef KARBONATOR_COLLECTION_DYNAMICSIZEARRAY_HPP
#define KARBONATOR_COLLECTION_DYNAMICSIZEARRAY_HPP

#include "karbonator/pp/basic.hpp"
#if KARBONATOR_PP_IS_INITIALIZER_LIST_SUPPORTED > 0
    #include <initializer_list>
#endif
#include <iterator>
//#include <cstdarg>
#include "DynamicSizeArrayBase.hpp"
#include "ArrayIterator.hpp"

namespace karbonator
{
namespace collection
{
    template <typename E>
    class DynamicSizeArray final
        : public DynamicSizeArrayBase
    {
    private:
    #if KARBONATOR_PP_IS_CONSTEXPR_SUPPORTED > 0
        static constexpr SizeType elementSize = sizeof(E);
    #else
        enum
        {
            elementSize = sizeof(E)
        };
    #endif

    public:
        typedef ConstArrayIterator<E> const_iterator;

        typedef ArrayIterator<E> iterator;

        //typedef std::reverse_iterator< ConstArrayIterator<E> > const_reverse_iterator;

        //typedef std::reverse_iterator< ArrayIterator<E> > reverse_iterator;

    public:
        DynamicSizeArray();

        DynamicSizeArray(const DynamicSizeArray<E>& source);

        DynamicSizeArray(DynamicSizeArray<E>&& source);

        template <typename IteratorType>
        DynamicSizeArray(IteratorType beginIter, IteratorType endIter);

        DynamicSizeArray(SizeType elementCount, const E& src = E());

        DynamicSizeArray(const E* pElements, SizeType elementCount);

        DynamicSizeArray(E*&& pAllocatedElements, SizeType elementCount);

        //static DynamicSizeArray<E> fromVarargs(SizeType elementCount, std::va_list varargs);

        //static DynamicSizeArray<E> fromElements(SizeType elementCount, ...);

    #if KARBONATOR_PP_IS_INITIALIZER_LIST_SUPPORTED > 0
        DynamicSizeArray(std::initializer_list<E> list);
    #endif

        virtual ~DynamicSizeArray();

        DynamicSizeArray<E>& operator =(const DynamicSizeArray<E>& rhs);

        DynamicSizeArray<E>& operator =(DynamicSizeArray<E>&& rhs);

    public:
        SizeType getElementCount() const;

        const E& operator [](SizeType index) const;

        E& operator [](SizeType index);

        const E& at(SizeType index) const;

        E& at(SizeType index);

        void set(SizeType index, const E& element);

        void set(SizeType index, E&& element);
        
        template <typename IteratorType>
        void set(SizeType srcStart, IteratorType destBegin, IteratorType destEnd);

    public:
        const_iterator cbegin() const;

        const_iterator cend() const;

        //const_reverse_iterator crbegin() const;

        //const_reverse_iterator crend() const;

        const_iterator begin() const;

        iterator begin();

        const_iterator end() const;

        iterator end();

        //const_reverse_iterator rbegin() const;

        //reverse_iterator rbegin();

        //const_reverse_iterator rend() const;

        //reverse_iterator rend();
        
    public:
        const E* getElementPointer() const;

    private:
        const E* getElementBytes() const;

        E* getElementBytes();

        void assertIndexInRange(SizeType index) const;
    };
}
}

#include "DynamicSizeArray.inl"

#endif
