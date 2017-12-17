#ifndef KAPHEIN_UTILITY_SELECTTYPE_HPP
#define KAPHEIN_UTILITY_SELECTTYPE_HPP

namespace kaphein
{
namespace utility
{
    template <
        bool condition
        , typename TrueType
        , typename FalseType
    >
    struct SelectType;

    template <
        typename TrueType
        , typename FalseType
    >
    struct SelectType<true, TrueType, FalseType>
    {
        typedef TrueType SelectedType;
    };

    template <
        typename TrueType
        , typename FalseType
    >
    struct SelectType<false, TrueType, FalseType>
    {
        typedef FalseType SelectedType;
    };
}
}

#endif
