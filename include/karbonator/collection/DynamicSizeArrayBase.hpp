#ifndef KARBONATOR_COLLECTION_DYNAMICSIZEARRAYBASE_HPP
#define KARBONATOR_COLLECTION_DYNAMICSIZEARRAYBASE_HPP

#include "karbonator/pp/basic.hpp"

namespace karbonator
{
namespace collection
{
    class KARBONATOR_PP_DLL_API DynamicSizeArrayBase
    {
    protected:
        DynamicSizeArrayBase(SizeType byteCount);

        DynamicSizeArrayBase(const DynamicSizeArrayBase& source);

        DynamicSizeArrayBase(DynamicSizeArrayBase&& source);

        DynamicSizeArrayBase(void*&& pAllocatedElements, SizeType byteCount);

    public:
        virtual ~DynamicSizeArrayBase();

    protected:
        DynamicSizeArrayBase& operator =(const DynamicSizeArrayBase& rhs);

        DynamicSizeArrayBase& operator =(DynamicSizeArrayBase&& rhs);

    protected:
        SizeType getByteCount() const;

        const void* getBytes() const;

        void* getBytes();

        const void* getElementBytes(SizeType elementIndex, SizeType elementSize) const;

        void* getElementBytes(SizeType elementIndex, SizeType elementSize);
        
        void constructContainer(SizeType byteCount);

        void destructSelf();

        void invalidateSelf();

    protected:
        static void* allocate(SizeType byteCount);

        static void free(void* target);

    private:
        char* pStart_;

        char* pEnd_;
    };
}
}

#endif
