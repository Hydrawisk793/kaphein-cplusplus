#ifndef KAPHEIN_FUNCTIONAL_FUNCTIONWRAPPER_HPP
#define KAPHEIN_FUNCTIONAL_FUNCTIONWRAPPER_HPP

#include "macro.hpp"
#include "FunctionWrapperBase.hpp"

namespace kaphein
{
namespace functional
{
#define KAPHEIN_xx_DECLARE_CLASS(...) \
    template < \
        typename R \
        ,
        KAPHEIN_x_EXPAND(KAPHEIN_x_MAKE_TYPENAME_LIST(__VA_ARGS__)) \
    > \
    class FunctionWrapper \
        : public FunctionWrapperBase \
    { \
    public: \
        virtual R operator ()(
            KAPHEIN_x_EXPAND(KAPHEIN_x_MAKE_TYPE_LIST(__VA_ARGS__))
        ) const = 0; \
    }; \
}

KAPHEIN_xx_DECLARE_CLASS(A1)

KAPHEIN_xx_DECLARE_CLASS(A1, A2)

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3)

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4)

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5)

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6)

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7)

KAPHEIN_xx_DECLARE_CLASS(A1, A2, A3, A4, A5, A6, A7, A8)

#undef KAPHEIN_xx_DECLARE_CLASS
}

#endif
