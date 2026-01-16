//#include "util/comb.hpp"
//#include <gtest/gtest.h>
//
//// 测试组合数计算
//TEST(CombinationTest, ValidInputs) {
//    EXPECT_EQ(comb::combination(5, 2), 10);  // 5C2 = 10
//    EXPECT_EQ(comb::combination(6, 3), 20);  // 6C3 = 20
//    EXPECT_EQ(comb::combination(10, 0), 1);  // 10C0 = 1
//    EXPECT_EQ(comb::combination(10, 10), 1); // 10C10 = 1
//}
//
//// 测试非法输入
//TEST(CombinationTest, InvalidInputs) {
//    EXPECT_EQ(comb::combination(5, -1), 0);  // k < 0
//    EXPECT_EQ(comb::combination(5, 6), 0);  // k > n
//}
//
//// 测试边界情况
//TEST(CombinationTest, EdgeCases) {
//    EXPECT_EQ(comb::combination(0, 0), 1);  // 0C0 = 1
//    EXPECT_EQ(comb::combination(1, 0), 1);  // 1C0 = 1
//    EXPECT_EQ(comb::combination(1, 1), 1);  // 1C1 = 1
//}
//
//// 测试大数情况
//TEST(CombinationTest, LargeNumbers) {
//    EXPECT_EQ(comb::combination(20, 10), 184756); // 20C10 = 184756
//    EXPECT_EQ(comb::combination(100, 50), 538992043); // 验证大数结果 (MOD 限制)
//}
//
//// // 测试大数情况2
//// TEST(CombinationTest, LargeNumbers2) {
////     EXPECT_EQ(comb::combination(20, 10), 184756); // 20C10 = 184756
////     EXPECT_EQ(comb::combination(100, 50), 538992043); // 验证大数结果 (MOD 限制)
//// }
