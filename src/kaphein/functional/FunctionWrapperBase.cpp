#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstring>
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
            ? std::memcmp(pLhsBytes, pRhsBytes, lhsSize) < 0
            : (int)(lhsSize - rhsSize)
        );
    }
}
}
