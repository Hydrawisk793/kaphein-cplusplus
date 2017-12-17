#ifndef KAPHEIN_UNSUPPORTEDMETHODEXCEPTION_HPP
#define KAPHEIN_UNSUPPORTEDMETHODEXCEPTION_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "kaphein/cplusplus/Exception.hpp"

namespace kaphein
{
    class KAPHEIN_PP_DLL_API UnsupportedMethodException
        : public Exception
    {
    public:
        virtual ~UnsupportedMethodException();
    };
}

#endif
