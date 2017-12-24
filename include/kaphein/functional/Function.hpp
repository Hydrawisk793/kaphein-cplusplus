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

#ifndef KAPHEIN_FUNCTIONAL_FUNCTION_HPP
#define KAPHEIN_FUNCTIONAL_FUNCTION_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/functional/macro.hpp"
#include "kaphein/functional/FunctionBase.hpp"

namespace kaphein
{
namespace functional
{
#define KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(...) \
    template < \
        typename R \
        KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(__VA_ARGS__) \
    >

#define KAPHEIN_xx_THIS_TYPE(...) \
    Function< \
        R ( \
            KAPHEIN_x_MAKE_LIST(__VA_ARGS__) \
        ) \
    >

#define KAPHEIN_xx_FUNCTOR_DECLARE_COMMON() \
    static void* staticCtor( \
        void* pFunctor \
        , const void* pParam \
    ) \
    { \
        return new (pFunctor) Functor( \
            *static_cast<const Attribute*>(pParam) \
        ); \
    } \
        \
    static void* staticCopyCtor( \
        void* pFunctor \
        , const void* pSrc \
    ) \
    { \
        return new (pFunctor) Functor( \
            *static_cast<const Functor*>(pSrc) \
        ); \
    } \
        \
    static void staticDtor( \
        const void* pFunctor \
    ) \
    { \
        pFunctor; \
        static_cast<const Functor*>(pFunctor)->~Functor(); \
    } \
        \
    Functor( \
        const Attribute& attribute \
    ) \
        : attribute(attribute) \
    {} \
        \
    Functor( \
        const Functor& src \
    ) \
        : attribute(src.attribute) \
    {} \
        \
    Functor( \
        Functor&& src \
    ) \
        : attribute(std::move(src.attribute)) \
    {} \
        \
    Attribute attribute;

#define KAPHEIN_xx_DECLARE_CLASS_BODY(...) \
    private: \
        struct CallOperatorWrapper \
        { \
            R (*pOpFunc)( \
                void* \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            ); \
        }; \
         \
        template <typename E, bool IsConst, bool IsVolatile> \
        struct MethodPtrTypeCase {}; \
         \
        template <typename E> \
        struct MethodPtrTypeCase<E, false, false> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ); \
        }; \
         \
        template <typename E> \
        struct MethodPtrTypeCase<E, true, false> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) const; \
        }; \
         \
        template <typename E> \
        struct MethodPtrTypeCase<E, false, true> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) volatile; \
        }; \
         \
        template <typename E> \
        struct MethodPtrTypeCase<E, true, true> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) const volatile; \
        }; \
         \
    public: \
        template <typename E> \
        struct MethodPtrTypeSelector \
        { \
            typedef typename MethodPtrTypeCase< \
                E \
                , utility::IsConst<E>::value \
                , utility::IsVolatile<E>::value \
            >::type type; \
        }; \
         \
        typedef R (*FreeFunctionPtrType)( \
            KAPHEIN_x_MAKE_LIST(__VA_ARGS__) \
        ); \
         \
        typedef R ReturnType; \
         \
    public: \
        Function() \
            : FunctionBase() \
        {} \
         \
        Function( \
            const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& src \
        ) \
            : FunctionBase(src) \
        {} \
         \
        Function( \
            KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)&& src \
        ) \
            : FunctionBase(std::move(src)) \
        {} \
         \
        Function( \
            FreeFunctionPtrType pFreeFunc \
        ) \
            : FunctionBase() \
        { \
            struct Functor \
            { \
                struct Attribute \
                { \
                    FreeFunctionPtrType pFreeFunc; \
                }; \
                 \
                static R staticCallOp( \
                    void* pFunctor \
                    , KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
                ) \
                { \
                    return (*(static_cast<Functor*>(pFunctor)->attribute.pFreeFunc))( \
                        KAPHEIN_x_MAKE_ARGVAR_LIST(__VA_ARGS__) \
                    ); \
                } \
                 \
                KAPHEIN_xx_FUNCTOR_DECLARE_COMMON() \
            }; \
             \
            Functor::Attribute attribute; \
            attribute.pFreeFunc = pFreeFunc; \
             \
            CallOperatorWrapper callOpWrapper; \
            callOpWrapper.pOpFunc = Functor::staticCallOp; \
             \
            construct( \
                sizeof(Functor) \
                , &attribute \
                , Functor::staticCtor \
                , Functor::staticCopyCtor \
                , Functor::staticDtor \
                , sizeof(callOpWrapper) \
                , &callOpWrapper \
            ); \
        } \
         \
        template <typename E> \
        Function( \
            E& obj \
            , typename MethodPtrTypeSelector<E>::type pMethod \
        ) \
            : FunctionBase() \
        { \
            typedef typename MethodPtrTypeSelector<E>::type MethodPtrType; \
         \
            struct Functor \
            { \
                struct Attribute \
                { \
                    MethodPtrType pMethod; \
                     \
                    E* pObj; \
                }; \
                 \
                static R staticCallOp( \
                    void* pFunctor \
                    , KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
                ) \
                { \
                    const Attribute& attribute = static_cast<Functor*>(pFunctor)->attribute; \
                     \
                    return (attribute.pObj->*attribute.pMethod)( \
                        KAPHEIN_x_MAKE_ARGVAR_LIST(__VA_ARGS__) \
                    ); \
                } \
                 \
                KAPHEIN_xx_FUNCTOR_DECLARE_COMMON() \
            }; \
             \
            Functor::Attribute attribute; \
            attribute.pMethod = pMethod; \
            attribute.pObj = &obj; \
             \
            CallOperatorWrapper callOpWrapper; \
            callOpWrapper.pOpFunc = Functor::staticCallOp; \
             \
            construct( \
                sizeof(Functor) \
                , &attribute \
                , Functor::staticCtor \
                , Functor::staticCopyCtor \
                , Functor::staticDtor \
                , sizeof(callOpWrapper) \
                , &callOpWrapper \
            ); \
        } \
         \
        template <typename Callable> \
        Function( \
            Callable callable \
        ) \
            : FunctionBase() \
        { \
            struct Functor \
            { \
                typedef Callable Attribute; \
                 \
                static R staticCallOp( \
                    void* pFunctor \
                    , KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
                ) \
                { \
                    return static_cast<Functor*>(pFunctor)->attribute( \
                        KAPHEIN_x_MAKE_ARGVAR_LIST(__VA_ARGS__) \
                    ); \
                } \
                 \
                KAPHEIN_xx_FUNCTOR_DECLARE_COMMON() \
            }; \
             \
            CallOperatorWrapper callOpWrapper; \
            callOpWrapper.pOpFunc = Functor::staticCallOp; \
             \
            construct( \
                sizeof(Functor) \
                , &callable \
                , Functor::staticCtor \
                , Functor::staticCopyCtor \
                , Functor::staticDtor \
                , sizeof(callOpWrapper) \
                , &callOpWrapper \
            ); \
        } \
         \
        ~Function() \
        { \
            destruct(); \
         \
            FunctionBase::~FunctionBase(); \
        } \
         \
        KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& operator =( \
            KAPHEIN_xx_THIS_TYPE(__VA_ARGS__) rhs \
        ) \
        { \
            rhs.swap(*this); \
             \
            return *this; \
        } \
         \
    public: \
        R operator ()( \
            KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
        ) \
        { \
            return (*(static_cast<CallOperatorWrapper*>(pCallOperatorWrapper_)->pOpFunc))( \
                functor_ \
                , KAPHEIN_x_MAKE_ARGVAR_LIST(__VA_ARGS__) \
            ); \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator !( \
            const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
        ) \
        { \
            return wrapper.isNull(); \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator ==( \
            const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
            , std::nullptr_t /*nPtr*/ \
        ) \
        { \
            return wrapper.isNull(); \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator ==( \
            std::nullptr_t nPtr \
            , const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
        ) \
        { \
            return wrapper == nPtr; \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator !=( \
            const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
            , std::nullptr_t nPtr \
        ) \
        { \
            return !(wrapper == nPtr); \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator !=( \
            std::nullptr_t nPtr \
            , const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
        ) \
        { \
            return !(wrapper == nPtr); \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator ==( \
            const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
            , bool b \
        ) \
        { \
            return !wrapper.isNull() == b; \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator ==( \
            bool b \
            , const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
        ) \
        { \
            return wrapper == b; \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator !=( \
            const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
            , bool b \
        ) \
        { \
            return !(wrapper == nPtr); \
        } \
         \
        KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
        friend bool operator !=( \
            bool b \
            , const KAPHEIN_xx_THIS_TYPE(__VA_ARGS__)& wrapper \
        ) \
        { \
            return !(wrapper == nPtr); \
        } \
         \
        EXPLICIT_CAST operator bool() const \
        { \
            return !isNull(); \
        }

#define KAPHEIN_xx_DECLARE_CLASS(...) \
    /** \
     *  @since 2017-12-24 \
     */ \
    KAPHEIN_xx_DECLARE_TEMPLATE_HEADER(__VA_ARGS__) \
    class KAPHEIN_xx_THIS_TYPE(__VA_ARGS__) \
        : public FunctionBase \
    { \
        KAPHEIN_xx_DECLARE_CLASS_BODY(__VA_ARGS__) \
    };

    /**
     *  @since 2017-12-24
     */
    template <typename>
    class Function;

    KAPHEIN_xx_DECLARE_CLASS()
    KAPHEIN_xx_DECLARE_CLASS(A1)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15)
    KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16)

#undef KAPHEIN_xx_DECLARE_CLASS
#undef KAPHEIN_xx_DECLARE_CLASS_BODY
#undef KAPHEIN_xx_FUNCTOR_DECLARE_COMMON
#undef KAPHEIN_xx_THIS_TYPE
#undef KAPHEIN_xx_DECLARE_TEMPLATE_HEADER
}
}

#endif
