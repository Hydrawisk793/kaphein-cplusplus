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

#define _CRT_SECURE_NO_WARNINGS

#include <utility>
#include <cstdlib>
#include <cstring>
#include "kaphein/utility/func.hpp"
#include "kaphein/functional/FunctionBase.hpp"

namespace kaphein
{
namespace functional
{
    FunctionBase::FunctionBase()
        : pCopyCtorFunc_(nullptr)
        , pDtorFunc_(nullptr)
        , pCallOperatorWrapper_(nullptr)
        , functor_(nullptr)
        , callOperatorWrapperSize_(0)
        , functorSize_(0)
    {}

    FunctionBase::FunctionBase(
        const FunctionBase& src
    )
        : pCopyCtorFunc_(src.pCopyCtorFunc_)
        , pDtorFunc_(src.pDtorFunc_)
        , pCallOperatorWrapper_(nullptr)
        , functor_(nullptr)
        , callOperatorWrapperSize_(src.callOperatorWrapperSize_)
        , functorSize_(src.functorSize_)
    {
        pCallOperatorWrapper_ = std::malloc(callOperatorWrapperSize_);
        std::memcpy(pCallOperatorWrapper_, src.pCallOperatorWrapper_, sizeof(callOperatorWrapperSize_));

        functor_ = std::malloc(functorSize_);
        (*pCopyCtorFunc_)(functor_, src.functor_);
    }

    FunctionBase::FunctionBase(
        FunctionBase&& src
    )
        : pCopyCtorFunc_(std::move(src.pCopyCtorFunc_))
        , pDtorFunc_(std::move(src.pDtorFunc_))
        , pCallOperatorWrapper_(std::move(src.pCallOperatorWrapper_))
        , functor_(std::move(src.functor_))
        , callOperatorWrapperSize_(std::move(src.callOperatorWrapperSize_))
        , functorSize_(std::move(src.functorSize_))
    {
        src.invalidateSelf();
    }

    FunctionBase::~FunctionBase()
    {}
    
    void FunctionBase::swap(
        FunctionBase& rhs
    )
    {
        utility::swap(pCopyCtorFunc_, rhs.pCopyCtorFunc_);
        utility::swap(pDtorFunc_, rhs.pDtorFunc_);
        utility::swap(pCallOperatorWrapper_, rhs.pCallOperatorWrapper_);
        utility::swap(functor_, rhs.functor_);
        utility::swap(callOperatorWrapperSize_, rhs.callOperatorWrapperSize_);
        utility::swap(functorSize_, rhs.functorSize_);
    }
    
    bool FunctionBase::isNull() const
    {
        return pCallOperatorWrapper_ == nullptr
            && functor_ == nullptr
        ;
    }
    
    void FunctionBase::construct(
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
    )
    {
        pCopyCtorFunc_ = pCopyCtorFunc;
        pDtorFunc_ = pDtorFunc;
        callOperatorWrapperSize_ = callOperatorWrapperSize;
        functorSize_ = functorSize;
        
        pCallOperatorWrapper_ = std::malloc(callOperatorWrapperSize_);
        std::memcpy(pCallOperatorWrapper_, pCallOperatorWrapper, callOperatorWrapperSize_);

        functor_ = std::malloc(functorSize_);
        (*pCtorFunc)(functor_, pCtorParam);
    }

    void FunctionBase::destruct()
    {
        if(pCallOperatorWrapper_ != nullptr) {
            std::free(pCallOperatorWrapper_);
            pCallOperatorWrapper_ = nullptr;
        }
        
        if(functor_ != nullptr) {
            (*pDtorFunc_)(functor_);
            std::free(functor_);

            functor_ = nullptr;
        }
    }
    
    void FunctionBase::invalidateSelf()
    {
        pCallOperatorWrapper_ = nullptr;
        functor_ = nullptr;
    }
}
}
