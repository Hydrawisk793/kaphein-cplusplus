#ifndef KAPHEIN_FUNCTIONAL_FREEFUNCTIONWRAPPER_HPP
#define KAPHEIN_FUNCTIONAL_FREEFUNCTIONWRAPPER_HPP

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
        typename R
        , class A1
    >
    class FreeFunctionWrapper final
        : public FunctionWrapper<R, A1>
    {
    public:
        typedef R (*FunctionPointerType)(A1);

        struct Attribute
        {
            FunctionPointerType pFunction;
        };

    public:
        FreeFunctionWrapper();
        
        FreeFunctionWrapper(
            const FreeFunctionWrapper<R, A1>& src
        );

        FreeFunctionWrapper(
            FreeFunctionWrapper<R, A1>&& src
        );

        FreeFunctionWrapper(
            FunctionPointerType pFunction
        );

        FreeFunctionWrapper<R, A1>& operator =(
            const FreeFunctionWrapper<R, A1>& rhs
        );

        FreeFunctionWrapper<R, A1>& operator =(
            FreeFunctionWrapper<R, A1>&& rhs
        );

    public:
        virtual R operator ()(A1 a1) const
        {
            return (*attr_.pFunction)(a1);
        }

    protected:
        virtual void getPointerBytes(
            const void *& bytesOut
            , SizeType & sizeOut
        ) const
        {
            bytesOut = static_cast<const void *>(&attr_);
            sizeOut = sizeof(Attribute);
        }

    private:
        Attribute attr_;
    };
}
}

#endif
