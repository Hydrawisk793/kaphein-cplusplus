#ifndef KAPHEIN_DIVIDEBYZEROEXCEPTION_HPP
#define KAPHEIN_DIVIDEBYZEROEXCEPTION_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    class KAPHEIN_PP_DLL_API DivideByZeroException
        : public Exception
    {
    public:
        virtual ~DivideByZeroException();
    };
}

#endif
