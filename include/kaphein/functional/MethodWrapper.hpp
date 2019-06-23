#ifndef KAPHEIN_FUNCTIONAL_METHODWRAPPER_HPP
#define KAPHEIN_FUNCTIONAL_METHODWRAPPER_HPP

#include <utility>
#include "../utility/IsConst.hpp"
#include "../utility/IsVolatile.hpp"
#include "macro.hpp"
#include "FunctionWrapper.hpp"

namespace kaphein
{
namespace functional
{
#define KAPHEIN_xx_DECLARE_CLASS_BODY(...) \
    public: \
        template <bool IsConst, bool IsVolatile> \
        struct MethodPtrTypeSelector {}; \
         \
        template <> \
        struct MethodPtrTypeSelector<false, false> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ); \
        }; \
         \
        template <> \
        struct MethodPtrTypeSelector<true, false> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) const; \
        }; \
         \
        template <> \
        struct MethodPtrTypeSelector<false, true> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) volatile; \
        }; \
         \
        template <> \
        struct MethodPtrTypeSelector<true, true> \
        { \
            typedef R (E::*type)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) const volatile; \
        }; \
         \
        typedef typename MethodPtrTypeSelector< \
            utility::IsConst<E>::value \
            , utility::IsVolatile<E>::value \
        >::type MethodPtrType; \
         \
        struct Attribute \
        { \
            E* pObject; \
             \
            MethodPtrType pMethod; \
        }; \
         \
    public: \
        MethodWrapper() \
            : FunctionWrapper() \
            , attr_() \
        {} \
         \
        MethodWrapper( \
            const MethodWrapper< \
                E \
                , R \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            >& src \
        ) \
            : FunctionWrapper(src) \
            , attr_(src.attr_) \
        {} \
         \
        MethodWrapper( \
            MethodWrapper< \
                E \
                , R \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            >&& src \
        ) \
            : FunctionWrapper(std::move(src)) \
            , attr_(std::move(src.attr_)) \
        {} \
         \
        MethodWrapper( \
            E& obj \
            , MethodPtrType pMethod \
        ) \
            : FunctionWrapper() \
            , attr_() \
        { \
            attr_.pObject = &obj; \
            attr_.pMethod = pMethod; \
        } \
         \
        MethodWrapper< \
            E \
            , R \
            KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
        >& operator =( \
            const MethodWrapper< \
                E \
                , R \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            >& rhs \
        ) \
        { \
            FunctionWrapper< \
                R \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            >::operator =(std::move(rhs)); \
             \
            attr_ = rhs.attr_; \
             \
            return *this; \
        } \
         \
        MethodWrapper< \
            E \
            , R \
            KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
        >& operator =( \
            MethodWrapper< \
                E \
                , R \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            >&& rhs \
        ) \
        { \
            FunctionWrapper< \
                R \
                KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
            >::operator =(std::move(rhs)); \
             \
            attr_ = std::move(rhs.attr_); \
             \
            return *this; \
        } \
         \
    public: \
        virtual R operator ()( \
            KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
        ) const \
        { \
            return (attr_.pObject->*attr_.pMethod)( \
                KAPHEIN_x_MAKE_ARGVAR_LIST(__VA_ARGS__) \
            ); \
        } \
         \
    protected: \
        virtual void getPointerBytes( \
            const void*& bytesOut \
            , SizeType& sizeOut \
        ) const \
        { \
            bytesOut = static_cast<const void*>(&attr_); \
            sizeOut = sizeof(attr_); \
        } \
         \
    private: \
        Attribute attr_;
    
#define KAPHEIN_xx_DECLARE_CLASS(...) \
    /** \
     *  @brief  \
     *  @date 2017-04-10 \
     */ \
    template < \
        typename E \
        , typename R \
        KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(__VA_ARGS__) \
    > \
    class MethodWrapper< \
        E \
        , R \
        KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
    > \
        : public FunctionWrapper< \
            R \
            KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
        > \
    { \
        KAPHEIN_xx_DECLARE_CLASS_BODY(__VA_ARGS__) \
    };

template <
    typename E
    , typename R
    , typename A1 = Dummy
    , typename A2 = Dummy
    , typename A3 = Dummy
    , typename A4 = Dummy
    , typename A5 = Dummy
    , typename A6 = Dummy
    , typename A7 = Dummy
    , typename A8 = Dummy
    , typename A9 = Dummy
    , typename A10 = Dummy
    , typename A11 = Dummy
    , typename A12 = Dummy
    , typename A13 = Dummy
    , typename A14 = Dummy
    , typename A15 = Dummy
    , typename A16 = Dummy
>
class MethodWrapper
    : public FunctionWrapper<
        R
        , A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16
    >
{
    KAPHEIN_xx_DECLARE_CLASS_BODY(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16)
};

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8, A9)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4)
KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3)
KAPHEIN_xx_DECLARE_CLASS(A1, A2)
KAPHEIN_xx_DECLARE_CLASS(A1)
KAPHEIN_xx_DECLARE_CLASS()

#undef KAPHEIN_xx_DECLARE_CLASS
#undef KAPHEIN_xx_DECLARE_CLASS_BODY
}
}

#endif
