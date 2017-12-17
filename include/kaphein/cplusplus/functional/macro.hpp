/*
 *  Copyright (c) Hydrawisk793
 *  All rights reserved.
 *
 *  This code is licensed under the MIT License.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files(the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions :
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#ifndef KAPHEIN_FUNCTIONAL_MACRO_HPP
#define KAPHEIN_FUNCTIONAL_MACRO_HPP

#include "kaphein/cplusplus/pp/basic.hpp"

#define KAPHEIN_x_MAKE_LIST_0()
#define KAPHEIN_x_MAKE_LIST_1(_1) \
    _1
#define KAPHEIN_x_MAKE_LIST_2(_1, _2) \
    KAPHEIN_x_MAKE_LIST_1(_1) \
    , _2
#define KAPHEIN_x_MAKE_LIST_3(_1, _2, _3) \
    KAPHEIN_x_MAKE_LIST_2(_1, _2) \
    , _3
#define KAPHEIN_x_MAKE_LIST_4(_1, _2, _3, _4) \
    KAPHEIN_x_MAKE_LIST_3(_1, _2, _3) \
    , _4
#define KAPHEIN_x_MAKE_LIST_5(_1, _2, _3, _4, _5) \
    KAPHEIN_x_MAKE_LIST_4(_1, _2, _3, _4) \
    , _5
#define KAPHEIN_x_MAKE_LIST_6(_1, _2, _3, _4, _5, _6) \
    KAPHEIN_x_MAKE_LIST_5(_1, _2, _3, _4, _5) \
    , _6
#define KAPHEIN_x_MAKE_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    KAPHEIN_x_MAKE_LIST_6(_1, _2, _3, _4, _5, _6) \
    , _7
#define KAPHEIN_x_MAKE_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
    KAPHEIN_x_MAKE_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    , _8
#define KAPHEIN_x_MAKE_LIST___(count, ...) \
    KAPHEIN_x_EXPAND( \
        KAPHEIN_x_MAKE_LIST_ ## count (__VA_ARGS__) \
    )
#define KAPHEIN_x_MAKE_LIST__(count, ...) \
    KAPHEIN_x_MAKE_LIST___(count, __VA_ARGS__)
#define KAPHEIN_x_MAKE_LIST(...) \
    KAPHEIN_x_MAKE_LIST__( \
        KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__) \
        , __VA_ARGS__ \
    )

#define KAPHEIN_x_MAKE_OPTIONAL_LIST_0()
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_1(_1) \
    , _1
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_2(_1, _2) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_1(_1) \
    , _2
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_3(_1, _2, _3) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_2(_1, _2) \
    , _3
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_4(_1, _2, _3, _4) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_3(_1, _2, _3) \
    , _4
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_5(_1, _2, _3, _4, _5) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_4(_1, _2, _3, _4) \
    , _5
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_6(_1, _2, _3, _4, _5, _6) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_5(_1, _2, _3, _4, _5) \
    , _6
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_6(_1, _2, _3, _4, _5, _6) \
    , _7
#define KAPHEIN_x_MAKE_OPTIONAL_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    , _8
#define KAPHEIN_x_MAKE_OPTIONAL_LIST___(count, ...) \
    KAPHEIN_x_EXPAND( \
        KAPHEIN_x_MAKE_OPTIONAL_LIST_ ## count (__VA_ARGS__) \
    )
#define KAPHEIN_x_MAKE_OPTIONAL_LIST__(count, ...) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST___(count, __VA_ARGS__)
#define KAPHEIN_x_MAKE_OPTIONAL_LIST(...) \
    KAPHEIN_x_MAKE_OPTIONAL_LIST__( \
        KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__) \
        , __VA_ARGS__ \
    )

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
#define KAPHEIN_x_MAKE_TYPENAME_LIST_5(_1, _2, _3, _4, _5) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_4(_1, _2, _3, _4) \
    , typename _5
#define KAPHEIN_x_MAKE_TYPENAME_LIST_6(_1, _2, _3, _4, _5, _6) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_5(_1, _2, _3, _4, _5) \
    , typename _6
#define KAPHEIN_x_MAKE_TYPENAME_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_6(_1, _2, _3, _4, _5, _6) \
    , typename _7
#define KAPHEIN_x_MAKE_TYPENAME_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
    KAPHEIN_x_MAKE_TYPENAME_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    , typename _8
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
    
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_0()
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_1(_1) \
    , typename _1
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_2(_1, _2) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_1(_1) \
    , typename _2
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_3(_1, _2, _3) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_2(_1, _2) \
    , typename _3
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_4(_1, _2, _3, _4) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_3(_1, _2, _3) \
    , typename _4
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_5(_1, _2, _3, _4, _5) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_4(_1, _2, _3, _4) \
    , typename _5
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_6(_1, _2, _3, _4, _5, _6) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_5(_1, _2, _3, _4, _5) \
    , typename _6
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_6(_1, _2, _3, _4, _5, _6) \
    , typename _7
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_8(_1, _2, _3, _4, _5, _6, _7, _8) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_7(_1, _2, _3, _4, _5, _6, _7) \
    , typename _8
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST___(count, ...) \
    KAPHEIN_x_EXPAND( \
        KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST_ ## count (__VA_ARGS__) \
    )
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST__(count, ...) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST___(count, __VA_ARGS__)
#define KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(...) \
    KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST__( \
        KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__) \
        , __VA_ARGS__ \
    )

#define KAPHEIN_x_MAKE_ARGVAR_LIST_0()
#define KAPHEIN_x_MAKE_ARGVAR_LIST_1() \
    a1
#define KAPHEIN_x_MAKE_ARGVAR_LIST_2() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_1() \
    , a2
#define KAPHEIN_x_MAKE_ARGVAR_LIST_3() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_2() \
    , a3
#define KAPHEIN_x_MAKE_ARGVAR_LIST_4() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_3() \
    , a4
#define KAPHEIN_x_MAKE_ARGVAR_LIST_5() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_4() \
    , a5
#define KAPHEIN_x_MAKE_ARGVAR_LIST_6() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_5() \
    , a6
#define KAPHEIN_x_MAKE_ARGVAR_LIST_7() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_6() \
    , a7
#define KAPHEIN_x_MAKE_ARGVAR_LIST_8() \
    KAPHEIN_x_MAKE_ARGVAR_LIST_7() \
    , a8
#define KAPHEIN_x_MAKE_ARGVAR_LIST___(count, ...) \
    KAPHEIN_x_EXPAND( \
        KAPHEIN_x_MAKE_ARGVAR_LIST_ ## count (__VA_ARGS__) \
    )
#define KAPHEIN_x_MAKE_ARGVAR_LIST__(count, ...) \
    KAPHEIN_x_MAKE_ARGVAR_LIST___(count, __VA_ARGS__)
#define KAPHEIN_x_MAKE_ARGVAR_LIST(...) \
    KAPHEIN_x_MAKE_ARGVAR_LIST__( \
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
    KAPHEIN_x_MAKE_ARGUMENT_LIST_3(_1, _2, _3) \
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
#define KAPHEIN_x_MAKE_ARGUMENT_LIST___(count, ...) \
    KAPHEIN_x_EXPAND( \
        KAPHEIN_x_MAKE_ARGUMENT_LIST_ ## count (__VA_ARGS__) \
    )
#define KAPHEIN_x_MAKE_ARGUMENT_LIST__(count, ...) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST___(count, __VA_ARGS__)
#define KAPHEIN_x_MAKE_ARGUMENT_LIST(...) \
    KAPHEIN_x_MAKE_ARGUMENT_LIST__( \
        KAPHEIN_PP_GET_ARGUMENT_COUNT(__VA_ARGS__) \
        , __VA_ARGS__ \
    )

#define KAPHEIN_x_TYPE_NAMES(...) __VA_ARGS__
#define KAPHEIN_x_ARGUMENT_NAMES(...) __VA_ARGS__

#endif
