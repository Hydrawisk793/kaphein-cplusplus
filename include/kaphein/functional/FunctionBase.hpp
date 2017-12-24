/*
 *  Copyright (c) Hydrawisk793
 *  All rights reserved.
 *
 *  This code is licensed under the MIT License.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files(the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions :
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#ifndef KAPHEIN_FUNCTIONAL_FUNCTIONBASE_HPP
#define KAPHEIN_FUNCTIONAL_FUNCTIONBASE_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/functional/macro.hpp"

namespace kaphein
{
namespace functional
{
    /**
     *  @since 2017-12-24
     */
    class KAPHEIN_PP_DLL_API FunctionBase
    {
    protected:
        FunctionBase();

        FunctionBase(
            const FunctionBase& src
        );

        FunctionBase(
            FunctionBase&& src
        );

        ~FunctionBase();

    public:
        void swap(FunctionBase& rhs);
        
        bool isNull() const;
        
    protected:
        void construct(
            SizeType functorSize
            , const void* pCtorParam
            , void* (*pCtorFunc)(
                void*
                , const void*
            )
            , void* (*pCopyCtorFunc)(
                void*
                , const void*
            )
            , void (*pDtorFunc)(
                const void*
            )
            , SizeType callOperatorWrapperSize
            , const void* pCallOperatorWrapper
        );
        
        void destruct();

        void invalidateSelf();

    protected:
        void* (*pCopyCtorFunc_)(
            void*
            , const void*
        );

        void (*pDtorFunc_)(
            const void*
        );

        void* pCallOperatorWrapper_;

        void* functor_;

        SizeType callOperatorWrapperSize_;

        SizeType functorSize_;
    };
}
}

#endif
