//
//  powmod.hpp
//  algorithm
//
//  Created by Tianqi Zhu on 8/8/25.
//
#pragma once
#include <type_traits>
#include <cstdint>

namespace util {

// 动态模版本
template <class T, class U, class M>
T mod_pow(T x, U n, M mod) {
    static_assert(std::is_integral_v<T> &&
                  std::is_integral_v<U> &&
                  std::is_integral_v<M>,
                  "mod_pow requires integral types");
    
    if (mod == 0) return 0;

    // 统一到 long long 计算，避免 32 位溢出
    long long m = static_cast<long long>(mod);
    if (m < 0) m = -m;
    long long a = static_cast<long long>(x % m);
    if (a < 0) a += m;
    long long res = 1 % m;

    using UN = std::make_unsigned_t<std::common_type_t<U, uint64_t>>;
    UN e = static_cast<UN>(n);

    while (e > 0) {
        if (e & 1ULL) res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1ULL;
    }
    return static_cast<T>(res);
}

// 固定模版本
template <std::int64_t MOD, class T, class U>
T mod_pow_fixed(T x, U n) {
    static_assert(MOD > 0, "MOD must be positive");

    constexpr long long m = MOD;
    long long a = static_cast<long long>(x % m);
    if (a < 0) a += m;
    long long res = 1 % m;

    using UN = std::make_unsigned_t<std::common_type_t<U, uint64_t>>;
    UN e = static_cast<UN>(n);

    while (e > 0) {
        if (e & 1ULL) res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1ULL;
    }
    return static_cast<T>(res);
}

}
