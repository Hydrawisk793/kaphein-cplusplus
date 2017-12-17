#include <utility>
#include "kaphein/cplusplus/Exception.hpp"

namespace kaphein
{
    Exception::Exception()
    {}

    Exception::Exception(const Exception& o)
    {
        o;
    }

    Exception::Exception(Exception&& o)
    {
        o;
    }

    Exception::~Exception()
    {}
    
    Exception& Exception::operator =(const Exception& rhs)
    {
        if(this != &rhs) {
            
        }

        return *this;
    }

    Exception& Exception::operator =(Exception&& rhs)
    {
        if(this != &rhs) {
            
        }

        return *this;
    }
}
