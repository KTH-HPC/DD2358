#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test_fixture.hpp"

uint8_t readPins()
{
  // invoke the mocked function
  return LEDUnitTest::_ledMock->readPins();
}

TEST_F(LEDUnitTest, PortToIndex)
{
  // run the mocked function (that will be called by readInput())
  // run 4 times, return 0, 1, 2, 4
  EXPECT_CALL(*_ledMock,
              readPins())
              .Times(4)
              .WillOnce(testing::Return(0))
              .WillOnce(testing::Return(1))
              .WillOnce(testing::Return(2))
              .WillOnce(testing::Return(4));

  // perform tests
  EXPECT_EQ(-1, readInput());
  EXPECT_EQ(0, readInput());
  EXPECT_EQ(1, readInput());
  EXPECT_EQ(2, readInput());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
