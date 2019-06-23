#ifndef KAPHEIN_FUNCTIONAL_FREEFUNCTIONWRAPPER_HPP
#define KAPHEIN_FUNCTIONAL_FREEFUNCTIONWRAPPER_HPP

#include <utility>
#include "FunctionWrapper.hpp"

namespace kaphein
{
    namespace functional
    {
    #define KAPHEIN_xx_DECLARE_CLASS_BODY(...) \
        public: \
            typedef R (*FreeFunctionPtrType)( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ); \
             \
        private: \
            struct Attribute \
            { \
                FreeFunctionPtrType freeFunctionPtr; \
            }; \
             \
        public: \
            FreeFunctionWrapper(FreeFunctionPtrType freeFunctionPtr = nullptr) \
                : FunctionWrapper< \
                    R \
                    KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
                >() \
                , attr_() \
            { \
                attr_.freeFunctionPtr = freeFunctionPtr; \
            } \
             \
            FreeFunctionWrapper(const FreeFunctionWrapper& src) \
                : FunctionWrapper< \
                    R \
                    KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
                >(src) \
                , attr_(src.attr_) \
            { \
                attr_.freeFunctionPtr = src.attr_.freeFunctionPtr; \
            } \
             \
            FreeFunctionWrapper(FreeFunctionWrapper&& src) \
                : FunctionWrapper< \
                    R \
                    KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
                >(std::move(src)) \
                , attr_(std::move(src.attr_)) \
            { \
                attr_.freeFunctionPtr = std::move(src.attr_.freeFunctionPtr); \
            } \
             \
            FreeFunctionWrapper& operator =(const FreeFunctionWrapper& rhs) \
            { \
                FuntionWrapper< \
                    R \
                    KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
                >::operator =(rhs); \
                 \
                attr_ = rhs.attr_; \
                 \
                return *this; \
            } \
             \
            FreeFunctionWrapper& operator =(FreeFunctionWrapper&& rhs) \
            { \
                FuntionWrapper< \
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
                return (*attr_.freeFunctionPtr)( \
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
            typename R \
            KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(__VA_ARGS__) \
        > \
        class FreeFunctionWrapper< \
            R \
            KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
        > \
            : public FunctionWrapper< \
                R \
                KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(__VA_ARGS__) \
            > \
        { \
            KAPHEIN_xx_DECLARE_CLASS_BODY(__VA_ARGS__) \
        };

    template <
        typename R
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
    class FreeFunctionWrapper
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
