#ifndef KAPHEIN_INVALIDARGUMENTEXCEPTION_HPP
#define KAPHEIN_INVALIDARGUMENTEXCEPTION_HPP

#include "kaphein/pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class KAPHEIN_PP_DLL_API InvalidArgumentException
        : public Exception
    {
    public:
        virtual ~InvalidArgumentException();
    };
}

#endif
