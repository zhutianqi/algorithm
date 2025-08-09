//
//  comb.hpp
//  algorithm
//
//  Created by Tianqi Zhu on 8/8/25.
//
#pragma once
#include <cstdint>

namespace comb {

using ll = long long;
// 常量（放头文件用 inline constexpr 没问题）
inline constexpr int MOD  = 1'000'000'007;
inline constexpr int MAXN = 100'000 + 10;

// 仅声明：数组在 .cpp 里定义
extern ll fact[MAXN];
extern ll invFact[MAXN];

// 函数声明
//void precompute_factorials();
ll combination(int n, int k);

}
