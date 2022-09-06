#include <BigInt.h>
#include <gtest/gtest.h>

TEST(ConstructorTest, DefaultConstructor) {
  BigInt a;
  EXPECT_EQ(a.IsSignNegative(), false);
  EXPECT_EQ(a.GetDigits()[0], 0);
}
TEST(ConstructorTest, IntConstructor) {
  int value_lower_than_base = 100;
  BigInt a(value_lower_than_base);
  EXPECT_EQ(a.IsSignNegative(), false);
  EXPECT_EQ(a.GetDigits()[0], value_lower_than_base);
  BigInt b(-value_lower_than_base);
  EXPECT_EQ(b.IsSignNegative(), true);
  EXPECT_EQ(b.GetDigits()[0], value_lower_than_base);
  int value_greater_than_base = 2000000000;
  BigInt c(value_greater_than_base);
  EXPECT_EQ(c.IsSignNegative(), false);
  EXPECT_EQ(c.GetDigits()[0], value_greater_than_base % kBase);
  EXPECT_EQ(c.GetDigits()[1], value_greater_than_base / kBase);
  BigInt d(-value_greater_than_base);
  EXPECT_EQ(d.IsSignNegative(), true);
  EXPECT_EQ(d.GetDigits()[0], value_greater_than_base % kBase);
  EXPECT_EQ(d.GetDigits()[1], value_greater_than_base / kBase);
}
TEST(ConstructorTest,StringConstructor) {
  std::string str = "-1234567890098765456789876543234567";
  BigInt a(str);
  std::stringstream ss;
  std::string string_from_bigint;
  ss<<a;
  ss>>string_from_bigint;
  EXPECT_EQ(str,string_from_bigint);
}