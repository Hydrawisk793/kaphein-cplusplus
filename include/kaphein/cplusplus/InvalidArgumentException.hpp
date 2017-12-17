#ifndef KAPHEIN_INVALIDARGUMENTEXCEPTION_HPP
#define KAPHEIN_INVALIDARGUMENTEXCEPTION_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    class KAPHEIN_PP_DLL_API InvalidArgumentException
        : public Exception
    {
    public:
        virtual ~InvalidArgumentException();
    };
}

#endif
