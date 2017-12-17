#ifndef KAPHEIN_FUNCTIONAL_MACRO_HPP
#define KAPHEIN_FUNCTIONAL_MACRO_HPP

#define KAPHEIN_x_MAKE_TYPE_LIST_0()
#define KAPHEIN_x_MAKE_TYPE_LIST_1(_1) \
    _1
#define KAPHEIN_x_MAKE_TYPE_LIST_2(_1, _2) \
    KAPHEIN_x_MAKE_TYPE_LIST_1(_1) \
    , _2
#define KAPHEIN_x_MAKE_TYPE_LIST_3(_1, _2, _3) \
    KAPHEIN_x_MAKE_TYPE_LIST_2(_1, _2) \
    , _3
#define KAPHEIN_x_MAKE_TYPE_LIST_4(_1, _2, _3, _4) \
    KAPHEIN_x_MAKE_TYPE_LIST_4(_1, _2, _3) \
    , _4
#define KAPHEIN_x_MAKE_TYPE_LIST_5(_1, _2, _3, _4, _5) \
    KAPHEIN_x_MAKE_TYPE_LIST_4(_1, _2, _3, _4) \
    , _5
#define KAPHEIN_x_MAKE_TYPE_LIST_6(_1, _2, _3, _4, _5, _6) \
    KAPHEIN_x_MAKE_TYPE_LIST_5(_1, _2, _3, _4, _5) \
    , _6
#define KAPHEIN_x_MAKE_TYPE_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    KAPHEIN_x_MAKE_TYPE_LIST_6(_1, _2, _3, _4, _5, _6) \
    , _7
#define KAPHEIN_x_MAKE_TYPE_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
    KAPHEIN_x_MAKE_TYPE_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    , _8
#define KAPHEIN_x_MAKE_TYPE_LIST_(n, ...) \
    KAPHEIN_x_EXPAND(KAPHEIN_x_MAKE_TYPE_LIST_ ## n(__VA__ARGS__))
#define KAPHEIN_x_MAKE_TYPE_LIST(...) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_( \
        KAPHEIN_x_EXPAND(KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__)) \
        , __VA_ARGS__ \
    )
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_0(dummy)
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_1(_1) \
//    typename _1
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_2(_1, _2) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_1(_1) \
//    , typename _2
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_3(_1, _2, _3) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_2(_1, _2) \
//    , typename _3
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_4(_1, _2, _3, _4) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_3(_1, _2, _3) \
//    , typename _4
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_5(_1, _2, _3, _4, _5) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_4(_1, _2, _3, _4) \
//    , typename _5
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_6(_1, _2, _3, _4, _5, _6) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_5(_1, _2, _3, _4, _5) \
//    , typename _6
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_6(_1, _2, _3, _4, _5, _6) \
//    , typename _7
//#define KAPHEIN_x_MAKE_TYPENAME_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
//    , typename _8
//#define KAPHEIN_x_MAKE_TYPENAME_LIST___(n, ...) \
//    KAPHEIN_x_EXPAND( \
//        KAPHEIN_x_MAKE_TYPENAME_LIST_##n(__VA__ARGS__) \
//    )
//#define KAPHEIN_x_MAKE_TYPENAME_LIST__(n, ...) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST___(n, __VA__ARGS__)
//#define KAPHEIN_x_MAKE_TYPENAME_LIST(...) \
//    KAPHEIN_x_MAKE_TYPENAME_LIST__( \
//        KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__) \
//        , __VA_ARGS__ \
//    )
#define KAPHEIN_x_MAKE_TYPENAME_LIST_0(dummy)
#define KAPHEIN_x_MAKE_TYPENAME_LIST_1(_1) \
    typename _1
#define KAPHEIN_x_MAKE_TYPENAME_LIST_2(_1, _2) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_1(_1) \
    , typename _2
#define KAPHEIN_x_MAKE_TYPENAME_LIST_3(_1, _2, _3) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_2(_1, _2) \
    , typename _3
#define KAPHEIN_x_MAKE_TYPENAME_LIST_4(_1, _2, _3, _4) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_3(_1, _2, _3) \
    , typename _4
#define KAPHEIN_x_MAKE_TYPENAME_LIST___(count, ...) \
    KAPHEIN_x_EXPAND( \
        KAPHEIN_x_MAKE_TYPENAME_LIST_ ## count (__VA_ARGS__) \
    )
#define KAPHEIN_x_MAKE_TYPENAME_LIST__(count, ...) \
    KAPHEIN_x_MAKE_TYPENAME_LIST___(count, __VA_ARGS__)
#define KAPHEIN_x_MAKE_TYPENAME_LIST(...) \
    KAPHEIN_x_MAKE_TYPENAME_LIST__( \
        KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__) \
        , __VA_ARGS__ \
    )
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_0()
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_1(_1) \
    _1 a1
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_2(_1, _2) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_1(_1) \
    , _2 a2
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_3(_1, _2, _3) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_2(_1, _2) \
    , _3 a3
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_4(_1, _2, _3, _4) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_4(_1, _2, _3) \
    , _4 a4
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_5(_1, _2, _3, _4, _5) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_4(_1, _2, _3, _4) \
    , _5 a5
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_6(_1, _2, _3, _4, _5, _6) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_5(_1, _2, _3, _4, _5) \
    , _6 a6
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_6(_1, _2, _3, _4, _5, _6) \
    , _7 a7
#define KAPHEIN_x_MAKE_ARGUMENT_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    , _8 a8
#define KAPHEIN_x_TYPE_NAMES(...) __VA_ARGS__
#define KAPHEIN_x_ARGUMENT_NAMES(...) __VA_ARGS__

#endif
