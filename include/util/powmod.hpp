//
//  powmod.hpp
//  algorithm
//
//  Created by Tianqi Zhu on 8/8/25.
//
#pragma once
#include <type_traits>
namespace util {

template <class T, class U, class M>
T mod_pow(T x, U n, M mod) {
    static_assert(std::is_integral_v<T> &&
                  std::is_integral_v<U> &&
                  std::is_integral_v<M>,
                  "mod_pow requires integral types");
    
    if (mod == 0) return 0;
    x %= mod;
    if (x < 0) x += mod;
    T res = static_cast<T>(1 % mod);
    
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

template <std::int64_t MOD, class T, class U>
T mod_pow_fixed(T x, U n) {
    static_assert(MOD > 0, "MOD must be positive");
    x %= MOD;
    if (x < 0) x += MOD;
    T res = static_cast<T>(1 % MOD);
    
    while (n > 0) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

}

#include "powmod.tpp"
