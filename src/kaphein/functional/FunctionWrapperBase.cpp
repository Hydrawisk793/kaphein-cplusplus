#include <kaphein/mem/utils.h>
#include "kaphein/functional/FunctionWrapperBase.hpp"

namespace kaphein
{
namespace functional
{
    FunctionWrapperBase::~FunctionWrapperBase()
    {}

    bool FunctionWrapperBase::operator ==(
        const FunctionWrapperBase& rhs
    ) const
    {
        SizeType lhsSize;
        SizeType rhsSize;
        const void* pLhsBytes;
        const void* pRhsBytes;

        getPointerBytes(pLhsBytes, lhsSize);
        rhs.getPointerBytes(pRhsBytes, rhsSize);
        
        return compareBytes(
            pLhsBytes, lhsSize
            , pRhsBytes, rhsSize
        ) == 0;
    }

    bool FunctionWrapperBase::operator !=(
        const FunctionWrapperBase& rhs
    ) const
    {
        return !(*this == rhs);
    }

    bool FunctionWrapperBase::operator <(
        const FunctionWrapperBase& rhs
    ) const
    {
        SizeType lhsSize;
        SizeType rhsSize;
        const void* pLhsBytes;
        const void* pRhsBytes;

        getPointerBytes(pLhsBytes, lhsSize);
        rhs.getPointerBytes(pRhsBytes, rhsSize);
        
        return compareBytes(
            pLhsBytes, lhsSize
            , pRhsBytes, rhsSize
        ) < 0;
    }

    bool FunctionWrapperBase::operator >=(
        const FunctionWrapperBase& rhs
    ) const
    {
        return !(*this < rhs);
    }

    bool FunctionWrapperBase::operator <=(
        const FunctionWrapperBase& rhs
    ) const
    {
        SizeType lhsSize;
        SizeType rhsSize;
        const void* pLhsBytes;
        const void* pRhsBytes;

        getPointerBytes(pLhsBytes, lhsSize);
        rhs.getPointerBytes(pRhsBytes, rhsSize);
        
        return compareBytes(
            pLhsBytes, lhsSize
            , pRhsBytes, rhsSize
        ) <= 0;
    }
    
    bool FunctionWrapperBase::operator >(
        const FunctionWrapperBase& rhs
    ) const
    {
        return !(*this <= rhs);
    }

    int FunctionWrapperBase::compareBytes(
        const void* pLhsBytes
        , SizeType lhsSize
        , const void* pRhsBytes
        , SizeType rhsSize
    )
    {
        return (
            lhsSize == rhsSize
            ? kaphein_mem_compare(pLhsBytes, lhsSize, pRhsBytes, rhsSize) < 0
            : (int)(lhsSize - rhsSize)
        );
    }
}
}
