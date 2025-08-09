//
//  test_powmod.cpp
//  algorithm
//
//  Created by Tianqi Zhu on 8/9/25.
//xxxx
#include "util/powmod.hpp"
#include <gtest/gtest.h>

// 测试常规情况
TEST(PowModTest, SmallNumbers) {
    EXPECT_EQ(util::mod_pow(2, 3, 5), 3);   // 2^3 = 8, 8 % 5 = 3
    EXPECT_EQ(util::mod_pow(5, 2, 13), 12); // 5^2 = 25, 25 % 13 = 12
}

// 测试指数为 0
TEST(PowModTest, ExponentZero) {
    EXPECT_EQ(util::mod_pow(7, 0, 10), 1);  // x^0 % m = 1
}

// 测试模数为 1（结果总是 0）
TEST(PowModTest, ModIsOne) {
    EXPECT_EQ(util::mod_pow(12345, 6789, 1), 0);
}

// 测试大指数
TEST(PowModTest, LargeExponent) {
    EXPECT_EQ(util::mod_pow(2, 50, 1000), 624); // 验证大指数不会溢出
}

// 测试大数 + 质数模
TEST(PowModTest, LargeNumbersPrimeMod) {
    EXPECT_EQ(util::mod_pow(123456789, 987654321, 1000000007), 652541198);
}

TEST(PowModFixedTest, LargeNumbersPrimeMod1000000007) {
    EXPECT_EQ(util::mod_pow_fixed<1000000007>(123456789, 987654321), 652541198);
}

TEST(PowModFixedTest, LargeNumbersPrimeMod1000000008) {
    EXPECT_EQ(util::mod_pow_fixed<1000000008>(123456789, 987654321), 748228797);
}
