//
//  powmod.cpp
//  algorithm
//
//  Created by Tianqi Zhu on 8/8/25.
//

#include <mutex>
#include <cassert>
#include "all.hpp"  // 你的头文件路径，如需改名自行调整

namespace comb {

// 在 .cpp 里定义数组
ll fact[MAXN];
ll invFact[MAXN];

// 只初始化一次的标记
static std::once_flag g_once;

// 实际初始化逻辑
static void init_tables() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = (fact[i - 1] * static_cast<ll>(i)) % MOD;

    invFact[MAXN - 1] = util::mod_pow_fixed<MOD>(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 1; --i)
        invFact[i] = (invFact[i + 1] * static_cast<ll>(i + 1)) % MOD;
    // invFact[0] 已在开头设为 1
}

//void precompute_factorials() {
//    std::call_once(g_once, init_tables);
//}

ll combination(int n, int k) {
    std::call_once(g_once, init_tables);  // 懒初始化，线程安全
    if (k < 0 || k > n) return 0;
    // 若需要，放开断言或改成返回 0/抛异常
    assert(n < MAXN && "n >= MAXN: increase MAXN or preprocess more.");
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}

} // namespace comb
