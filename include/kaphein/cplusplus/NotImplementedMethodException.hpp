#ifndef KAPHEIN_NOTIMPLEMENTEDMETHODEXCEPTION_HPP
#define KAPHEIN_NOTIMPLEMENTEDMETHODEXCEPTION_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "kaphein/cplusplus/Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class KAPHEIN_PP_DLL_API NotImplementedMethodException
        : public Exception
    {
    public:
        virtual ~NotImplementedMethodException();
    };
}

#endif
