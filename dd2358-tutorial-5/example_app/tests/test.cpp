#include <gtest/gtest.h>

extern "C" {

#include "division.h"
#include "power.h"
#include "product.h"
#include "sum.h"

}

TEST(AppTest, Sum) {
    ASSERT_DOUBLE_EQ(2, sum(1, 1));
    ASSERT_DOUBLE_EQ(5, sum(3, 2));
    ASSERT_DOUBLE_EQ(10, sum(7, 3));
}

TEST(AppTest, Power) {
    ASSERT_DOUBLE_EQ(4, power(2, 2));
    ASSERT_DOUBLE_EQ(27, power(3, 3));
}

TEST(AppTest, Division) {
  ASSERT_DOUBLE_EQ(2, division(4, 2));
  ASSERT_DOUBLE_EQ(4, division(16, 4));
}

TEST(AppTest, Product) {
  ASSERT_DOUBLE_EQ(2, product(1, 2));
  ASSERT_DOUBLE_EQ(4, product(2, 2));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
