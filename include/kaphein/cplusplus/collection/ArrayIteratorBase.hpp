#ifndef KAPHEIN_COLLECTION_ARRAYITERATORBASE_HPP
#define KAPHEIN_COLLECTION_ARRAYITERATORBASE_HPP

#include "kaphein/cplusplus/pp/basic.hpp"

namespace kaphein
{
namespace collection
{
    class KAPHEIN_PP_DLL_API ArrayIteratorBase
    {
    public:
        typedef PtrDiff difference_type;

    protected:
        ArrayIteratorBase();

        ArrayIteratorBase(const ArrayIteratorBase& src);

        ArrayIteratorBase(ArrayIteratorBase&& src);

        ArrayIteratorBase(const void* pStart, const void* pEnd);

        ArrayIteratorBase(const void* pStart, const void* pEnd, const void* pCurrent);

    public:
        virtual ~ArrayIteratorBase();

    protected:
        ArrayIteratorBase& operator =(const ArrayIteratorBase& rhs);

        ArrayIteratorBase& operator =(ArrayIteratorBase&& rhs);

    protected:
        const void* getStart() const;

        const void* getEnd() const;

        const void* getCurrent() const;

    public:
        void moveToNext(SizeType elementSize);

        void moveToNext(SizeType elementSize, difference_type diff);

        void moveToPrevious(SizeType elementSize);

        void moveToPrevious(SizeType elementSize, difference_type diff);

        difference_type getDifference(const ArrayIteratorBase& rhs) const;

    public:
        bool equals(const ArrayIteratorBase& rhs) const;

        bool lessThan(const ArrayIteratorBase& rhs) const;

        bool lessThanOrEqualTo(const ArrayIteratorBase& rhs) const;

    private:
        void invalidateSelf();

    private:
        const char* pStart_;

        const char* pEnd_;

        const char* pCurrent_;
    };
}
}

#endif
