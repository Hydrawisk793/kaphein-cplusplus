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

#ifndef KAPHEIN_FUNCTIONAL_METHODWRAPPER_HPP
#define KAPHEIN_FUNCTIONAL_METHODWRAPPER_HPP

#include "FunctionWrapper.hpp"

namespace kaphein
{
namespace functional
{
    /**
     *  @brief 
     *  @date 2017-04-10
     */
    template <
        typename E
        , typename R
        , class A1, class A2, class A3, class A4
    >
    class MethodWrapper final
        : public FunctionWrapper<R, A1, A2, A3, A4>
    {
    public:
        typedef R (E::*MethodPointerType)(A1 a1, A2 a2, A3 a3, A4 a4);

        struct Attribute
        {
            E* pObject;

            MethodPointerType pMethod;
        };

    public:
        MethodWrapper();

        MethodWrapper(
            const MethodWrapper<E, R, A1, A2, A3, A4>& src
        );

        MethodWrapper(
            MethodWrapper<E, R, A1, A2, A3, A4>&& src
        );

        MethodWrapper(
            E* pObject
            , MethodPointerType pMethod
        );

        MethodWrapper<E, R, A1, A2, A3, A4>& operator (
            const MethodWrapper<E, R, A1, A2, A3, A4>& rhs
        );

        MethodWrapper<E, R, A1, A2, A3, A4>& operator (
            MethodWrapper<E, R, A1, A2, A3, A4>&& rhs
        );

    public:
        virtual R operator ()(A1 a1, A2 a2, A3 a3, A4 a4) const
        {
            return (attr_.pObject->*attr_.pMethod)(a1, a2, a3, a4);
        }

    protected:
        virtual void getPointerBytes(
            const void *& bytesOut
            , SizeType & sizeOut
        ) const
        {
            *bytesOut = static_cast<const void*>(&attr_);
            *sizeOut = sizeof(attr_);
        }

    private:
        Attribute attr_;
    };
}
}

#endif
