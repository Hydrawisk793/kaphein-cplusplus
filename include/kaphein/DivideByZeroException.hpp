#ifndef KAPHEIN_DIVIDEBYZEROEXCEPTION_HPP
#define KAPHEIN_DIVIDEBYZEROEXCEPTION_HPP

#include "kaphein/pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class KAPHEIN_PP_DLL_API DivideByZeroException
        : public Exception
    {
    public:
        virtual ~DivideByZeroException();
    };
}

#endif
