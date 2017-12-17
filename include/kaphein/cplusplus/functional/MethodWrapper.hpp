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
