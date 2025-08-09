#include "all.hpp"  // 你的头文件路径，如需改名自行调整

// 用CLT可以求多个独立事件发生的概率
// Var(X)=E[(X−E[X])^2]
// var(X + Y) = var(X) + var(Y) if X and Y are independent ie. cov = 0 (定理推倒)

// CLT: n 个独立同分布版 N(μ,σ^2) S = X_1 + ...... + X_n
// 标准化后: (S - nμ）/ (σ * sqrt(n)) “依分布收敛”（convergence in distribution）到 N(0,1)

// 得知随机变量S 的分布后 再求 p（X > or < constant）
// 方法就是 Z是N(0,1) ， z是一个threshhold， 找 Φ(z)
// P(Z>z)=1−Φ(z) P(Z<z)= Φ(z) Φ(z) = 正态分布的累积分布函数（CDF）
// φ(z)是 pdf

// CLT 对于独立 不同分布的也是有用的 但要满足一定条件

namespace stats {

    inline Dist clt_iid_params_sigma(double mu, double sigma, double scale) {
        double Mu = scale * mu;
        double Sigma = sqrt(scale) * sigma; // 因为 Var_sum = scale * sigma^2
        return { Mu, Sigma };
    }

}