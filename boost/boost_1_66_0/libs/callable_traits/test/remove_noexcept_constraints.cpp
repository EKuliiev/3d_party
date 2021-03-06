/*
Copyright Barrett Adair 2016-2017

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)

*/

#include <boost/callable_traits/remove_noexcept.hpp>
#include <tuple>
#include "test.hpp"

#ifndef BOOST_CLBL_TRTS_ENABLE_NOEXCEPT_TYPES
int main(){}
#else

template<typename T>
struct is_substitution_failure_remove_noexcept {

    template<typename>
    static auto test(...) -> std::true_type;

    template<typename A,
        typename std::remove_reference<
            TRAIT(remove_noexcept, A)>::type* = nullptr>
    static auto test(int) -> std::false_type;

    static constexpr bool value = decltype(test<T>(0))::value;
};

struct foo;

int main() {

    auto lambda = [](){};

    CT_ASSERT(is_substitution_failure_remove_noexcept<decltype(lambda)>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<decltype(lambda)&>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int &>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int (* const &)()>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int (foo::* &)()>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int (foo::* const)()>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int (foo::* const &)()>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<int (foo::* volatile)()>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<void>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<void*>::value);
    CT_ASSERT(is_substitution_failure_remove_noexcept<void(**)()>::value);
}

#endif //#ifndef BOOST_CLBL_TRTS_ENABLE_TRANSACTION_SAFE
