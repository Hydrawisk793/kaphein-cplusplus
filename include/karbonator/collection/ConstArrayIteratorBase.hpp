#ifndef KARBONATOR_COLLECTION_CONSTARRAYITERATORBASE_HPP
#define KARBONATOR_COLLECTION_CONSTARRAYITERATORBASE_HPP

#include "karbonator/pp/basic.hpp"

namespace karbonator
{
namespace collection
{
    class KARBONATOR_PP_DLL_API ConstArrayIteratorBase
    {
    protected:
        ConstArrayIteratorBase();

        ConstArrayIteratorBase(const ConstArrayIteratorBase& src);

        ConstArrayIteratorBase(ConstArrayIteratorBase&& src);

        ConstArrayIteratorBase(const void* pStart, const void* pEnd);

        ConstArrayIteratorBase(const void* pStart, const void* pEnd, const void* pCurrent);

    public:
        virtual ~ConstArrayIteratorBase();

    protected:
        ConstArrayIteratorBase& operator =(const ConstArrayIteratorBase& rhs);

        ConstArrayIteratorBase& operator =(ConstArrayIteratorBase&& rhs);

    protected:
        const void* getStart() const;

        const void* getEnd() const;

        const void* getCurrent() const;

    public:
        void moveToNext(SizeType elementSize);

        void moveToNext(SizeType elementSize, PtrDiff diff);

        void moveToPrevious(SizeType elementSize);

        void moveToPrevious(SizeType elementSize, PtrDiff diff);

        PtrDiff getDifference(const ConstArrayIteratorBase& rhs) const;

    public:
        bool equals(const ConstArrayIteratorBase& rhs) const;

        bool lessThan(const ConstArrayIteratorBase& rhs) const;

        bool lessThanOrEqualTo(const ConstArrayIteratorBase& rhs) const;

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
