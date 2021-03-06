#ifndef KAPHEIN_FUNCTIONAL_FUNCTIONWRAPPERBASE_HPP
#define KAPHEIN_FUNCTIONAL_FUNCTIONWRAPPERBASE_HPP

#include "../pp/basic.hpp"

namespace kaphein
{
    namespace functional
    {
        class
        KAPHEIN_ATTRIBUTE_DLL_API
        FunctionWrapperBase
        {
        public:
            virtual ~FunctionWrapperBase();

            //virtual FunctionWrapperBase* clone(char* pDest, SizeType destSize) const = 0;

        public:
            bool operator ==(const FunctionWrapperBase& rhs) const;

            bool operator !=(const FunctionWrapperBase& rhs) const;

            bool operator <(const FunctionWrapperBase& rhs) const;

            bool operator >=(const FunctionWrapperBase& rhs) const;

            bool operator <=(const FunctionWrapperBase& rhs) const;

            bool operator >(const FunctionWrapperBase& rhs) const;
        
        protected:
            virtual void getPointerBytes(
                const void*& bytesOut
                , SizeType& sizeOut
            ) const = 0;

        private:
            static int compareBytes(
                const void* pLhsBytes
                , SizeType lhsSize
                , const void* pRhsBytes
                , SizeType rhsSize
            );
        };
    }
}

#endif
