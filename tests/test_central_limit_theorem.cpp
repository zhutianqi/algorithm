//#include "stats.hpp"
//#include <gtest/gtest.h>
//
//// 测试 IID 情况的均值和标准差计算
//TEST(CLTTest, IIDParamsSigma) {
//    stats::Dist result = stats::clt_iid_params_sigma(10.0, 2.0, 5.0);
//    EXPECT_DOUBLE_EQ(result.mu, 50.0);       // Mu = scale * mu = 5 * 10
//    EXPECT_DOUBLE_EQ(result.sigma, sqrt(20.0)); // Sigma = sqrt(scale) * sigma = sqrt(5) * 2
//}
//
//// 测试 IID 情况的概率计算
//TEST(CLTTest, IIDProbLess) {
//    double prob = stats::clt_iid_prob_less(10.0, 2.0, 5.0, 55.0);
//    EXPECT_NEAR(prob, 0.868, 0.001); // 预期概率值（基于正态分布 CDF 的近似值）
//}
//
//// 测试 IND 情况的均值和标准差计算
//TEST(CLTTest, INDParamsSigma) {
//    std::vector<stats::Dist> dists = {
//        {10.0, 2.0}, // mu = 10, sigma = 2
//        {15.0, 3.0}, // mu = 15, sigma = 3
//        {20.0, 4.0}  // mu = 20, sigma = 4
//    };
//    stats::Dist result = stats::clt_ind_params_sigma(dists);
//    EXPECT_DOUBLE_EQ(result.mu, 45.0);       // Mu = sum of all mu = 10 + 15 + 20
//    EXPECT_DOUBLE_EQ(result.sigma, sqrt(29.0)); // Sigma = sqrt(sum of variances) = sqrt(2^2 + 3^2 + 4^2)
//}
//
//// 测试 IND 情况的概率计算
//TEST(CLTTest, INDProbLess) {
//    std::vector<stats::Dist> dists = {
//        {10.0, 2.0}, // mu = 10, sigma = 2
//        {15.0, 3.0}, // mu = 15, sigma = 3
//        {20.0, 4.0}  // mu = 20, sigma = 4
//    };
//    double prob = stats::clt_ind_prob_less(dists, 50.0);
//    EXPECT_NEAR(prob, 0.82342, 0.001); // 预期概率值（基于正态分布 CDF 的近似值）
//}
