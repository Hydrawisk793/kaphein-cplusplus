#ifndef KARBONATOR_COLLECTION_DYNAMICSIZEARRAY_INL
#define KARBONATOR_COLLECTION_DYNAMICSIZEARRAY_INL

#include <utility>
#include <new>
#include "karbonator/IndexOutOfRangeException.hpp"

namespace karbonator
{
namespace collection
{
    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray()
        : DynamicSizeArrayBase(0)
    {}

    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray(const DynamicSizeArray<E>& source)
        : DynamicSizeArrayBase(source)
    {
        const E* pSrc = source.getElementBytes();
        E* pDest = getElementBytes();

        for(SizeType i = getElementCount(); i > 0; ) {
            --i;

            new (pDest) E(*pSrc);
            ++pDest;
            ++pSrc;
        }
    }

    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray(DynamicSizeArray<E>&& source)
        : DynamicSizeArrayBase(std::move(source))
    {}

    template <typename E>
    template <typename IteratorType>
    DynamicSizeArray<E>::DynamicSizeArray(
        IteratorType beginIter
        , IteratorType endIter
    )
        : DynamicSizeArrayBase((endIter - beginIter) * DynamicSizeArray<E>::elementSize)
    {
        const SizeType elementCount = endIter - beginIter;

        E* pDest = getElementBytes();
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            new (pDest) E(*beginIter++);
            ++pDest;
        }
    }
    
    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray(SizeType elementCount, const E& src)
        : DynamicSizeArrayBase(elementCount * DynamicSizeArray<E>::elementSize)
    {
        E* pDest = getElementBytes();
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            new (pDest) E(src);
            ++pDest;
        }
    }

    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray(const E* pElements, SizeType elementCount)
        : DynamicSizeArrayBase(elementCount * DynamicSizeArray<E>::elementSize)
    {
        if(!pElements) {
            throw false;
        }

        E* pDest = getElementBytes();
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            new (pDest) E(*pElements);
            ++pDest;
            ++pElements;
        }
    }

    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray(E*&& pAllocatedElements, SizeType elementCount)
        : DynamicSizeArrayBase(std::move(pAllocatedElements), elementCount * DynamicSizeArray<E>::elementSize)
    {}

    ///**
    // *  TODO : Change the implementation.(Drop assignments.)
    // */
    //template <typename E>
    //DynamicSizeArray<E> DynamicSizeArray<E>::fromVarargs(
    //    SizeType elementCount,
    //    std::va_list varargs
    //)
    //{
    //    DynamicSizeArray<E> result(elementCount);

    //    for(SizeType i = 0; i < elementCount; ++i) {
    //        result[i] = va_arg(varargs, E);
    //    }

    //    return result;
    //}

    ///**
    // *  TODO : Change the implementation.(Drop assignments.)
    // */
    //template <typename E>
    //DynamicSizeArray<E> DynamicSizeArray<E>::fromElements(
    //    SizeType ec
    //    , ...
    //)
    //{
    //    DynamicSizeArray<E> result(ec);

    //    std::va_list varargs;
    //    va_start(varargs, ec);

    //    for(SizeType i = 0; i < ec; ++i) {
    //        result[i] = va_arg(varargs, E);
    //    }

    //    va_end(varargs);

    //    //const SizeType byteCount = getByteCount();

    //    //std::va_list vaList;
    //    //va_start(vaList, elementCount);

    //    //E* pDest = getElementBytes();
    //    //for(SizeType off = 0; off < byteCount; off += elementSize)
    //    //{
    //    //    new (pDest) E(va_arg(vaList, E));
    //    //    ++pDest;
    //    //}

    //    //va_end(vaList);

    //    return result;
    //}

#if KARBONATOR_PP_IS_INITIALIZER_LIST_SUPPORTED > 0
    template <typename E>
    DynamicSizeArray<E>::DynamicSizeArray(
        std::initializer_list<E> list
    )
        : elementCount_(std::end(list) - std::begin(list))
        , bytes_(nullptr)
    {
        const SizeType byteCount = getByteCount();
        bytes_ = new char[byteCount];

        auto iter = std::begin(list);
        for(SizeType off = 0; off < byteCount; off += elementSize)
        {
            new (bytes_ + off) E(*iter++);
        }
    }
#endif

    template <typename E>
    DynamicSizeArray<E>::~DynamicSizeArray()
    {
        destructSelf();
    }

    template <typename E>
    DynamicSizeArray<E>& DynamicSizeArray<E>::operator =(const DynamicSizeArray<E>& rhs)
    {
        if(this != &rhs) {
            const SizeType thisElemCnt = getElementCount();
            if(thisElemCnt != rhs.getElementCount()) {
                throw false;
            }

            for(SizeType i = thisElemCnt; i > 0; ) {
                --i;

                (*this)[i] = rhs[i];
            }
        }

        return *this;
    }

    template <typename E>
    DynamicSizeArray<E>& DynamicSizeArray<E>::operator =(DynamicSizeArray<E>&& rhs)
    {
        if(this != &rhs) {
            DynamicSizeArrayBase::operator =(std::move(rhs));
        }

        return *this;
    }

    template <typename E>
    SizeType DynamicSizeArray<E>::getElementCount() const
    {
        return getByteCount() / DynamicSizeArray<E>::elementSize;
    }

    template <typename E>
    const E& DynamicSizeArray<E>::operator [](SizeType index) const
    {
        return getElementBytes()[index];
    }

    template <typename E>
    E& DynamicSizeArray<E>::operator [](SizeType index)
    {
        return const_cast<E&>(
            const_cast<const DynamicSizeArray<E> *>(this)->operator [](index)
        );
    }

    template <typename E>
    const E& DynamicSizeArray<E>::at(SizeType index) const
    {
        assertIndexInRange(index);

        return (*this)[index];
    }

    template <typename E>
    E& DynamicSizeArray<E>::at(SizeType index)
    {
        return const_cast<E&>(const_cast<const DynamicSizeArray<E> *>(this)->at(index));
    }

    template <typename E>
    void DynamicSizeArray<E>::set(SizeType index, const E& element)
    {
        assertIndexInRange(index);

        (*this)[index] = element;
    }

    template <typename E>
    void DynamicSizeArray<E>::set(SizeType index, E&& element)
    {
        assertIndexInRange(index);

        (*this)[index] = std::move(element);
    }
    
    template <typename E>
    template <typename IteratorType>
    void DynamicSizeArray<E>::set(SizeType srcStart, IteratorType destBegin, IteratorType destEnd)
    {
        assertIndexInRange(srcStart);

        const SizeType elementCount = destEnd - destBegin;
        const SizeType srcEnd = srcStart + elementCount;
        assertIndexInRange(srcEnd);

        for(SizeType i = srcStart; i < srcEnd; ++i) {
            (*this)[i] = *destBegin++;
        }
    }

    template <typename E>
    typename DynamicSizeArray<E>::const_iterator DynamicSizeArray<E>::cbegin() const
    {
        return const_iterator(getElementBytes());
    }

    template <typename E>
    typename DynamicSizeArray<E>::const_iterator DynamicSizeArray<E>::cend() const
    {
        return const_iterator(getElementBytes() + getElementCount());
    }

    //template <typename E>
    //typename DynamicSizeArray<E>::const_reverse_iterator DynamicSizeArray<E>::crbegin() const
    //{
    //    return const_reverse_iterator(&((*this)[0]));
    //}

    //template <typename E>
    //typename DynamicSizeArray<E>::const_reverse_iterator DynamicSizeArray<E>::crend() const
    //{
    //    return const_reverse_iterator(&((*this)[elementCount_]));
    //}

    template <typename E>
    typename DynamicSizeArray<E>::const_iterator DynamicSizeArray<E>::begin() const
    {
        return cbegin();
    }

    template <typename E>
    typename DynamicSizeArray<E>::iterator DynamicSizeArray<E>::begin()
    {
        return iterator(getElementBytes());
    }

    template <typename E>
    typename DynamicSizeArray<E>::const_iterator DynamicSizeArray<E>::end() const
    {
        return cend();
    }

    template <typename E>
    typename DynamicSizeArray<E>::iterator DynamicSizeArray<E>::end()
    {
        return iterator(getElementBytes() + getElementCount());
    }

    //template <typename E>
    //typename DynamicSizeArray<E>::const_reverse_iterator DynamicSizeArray<E>::rbegin() const
    //{
    //    return crbegin();
    //}

    //template <typename E>
    //typename DynamicSizeArray<E>::reverse_iterator DynamicSizeArray<E>::rbegin()
    //{
    //    return reverse_iterator(&((*this)[0]));
    //}

    //template <typename E>
    //typename DynamicSizeArray<E>::const_reverse_iterator DynamicSizeArray<E>::rend() const
    //{
    //    return crend();
    //}

    //template <typename E>
    //typename DynamicSizeArray<E>::reverse_iterator DynamicSizeArray<E>::rend()
    //{
    //    return reverse_iterator(&((*this)[elementCount_]));
    //}

    template <typename E>
    const E* DynamicSizeArray<E>::getElementPointer() const
    {
        return getElementBytes();
    }

    template <typename E>
    const E* DynamicSizeArray<E>::getElementBytes() const
    {
        return static_cast<const E*>(getBytes());
    }

    template <typename E>
    E* DynamicSizeArray<E>::getElementBytes()
    {
        return static_cast<E*>(getBytes());
    }

    template <typename E>
    void DynamicSizeArray<E>::assertIndexInRange(SizeType index) const
    {
        if(index >= getElementCount())
        {
            throw IndexOutOfRangeException();
        }
    }
}
}

#endif
