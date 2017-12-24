#ifndef KAPHEIN_UTILITY_FUNC_HPP
#define KAPHEIN_UTILITY_FUNC_HPP

namespace kaphein
{
namespace utility
{
    template <typename T>
    void swap(T& lhs, T& rhs)
    {
        T temp = lhs;
        lhs = rhs;
        rhs = temp;
    }
}
}

#endif
