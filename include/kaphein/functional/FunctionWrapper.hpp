#ifndef KAPHEIN_FUNCTIONAL_FUNCTIONWRAPPER_HPP
#define KAPHEIN_FUNCTIONAL_FUNCTIONWRAPPER_HPP

#include "macro.hpp"
#include "Dummy.hpp"
#include "FunctionWrapperBase.hpp"

namespace kaphein
{
    namespace functional
    {
    #define KAPHEIN_xx_DECLARE_CLASS_BODY(...) \
        public: \
            virtual R operator ()( \
                KAPHEIN_x_MAKE_ARGUMENT_LIST(__VA_ARGS__) \
            ) const = 0;

    #define KAPHEIN_xx_DECLARE_CLASS(...) \
        /** \
         *  @brief  \
         *  @date 2017-04-10 \
         */ \
        template < \
            typename R \
            KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(__VA_ARGS__) \
        > \
        class FunctionWrapper< \
            R \
            KAPHEIN_x_MAKE_OPTIONAL_LIST(__VA_ARGS__) \
        > \
            : public FunctionWrapperBase \
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
    class FunctionWrapper
        : public FunctionWrapperBase
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
