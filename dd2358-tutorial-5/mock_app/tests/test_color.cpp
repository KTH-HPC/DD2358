#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "test_fixture.hpp"

int readInput()
{
  // invoke the mocked function
  return LEDUnitTest::_ledMock->readInput();
}

/* test case 1 */
TEST_F(LEDUnitTest, IndexToColor)
{
  // build the readInput() function that is called by printLedColor()
  // run three times, returning
  // 000 -> error
  // 001 -> first pin on,  red
  // 010 -> second pin on, green
  // 100 -> second pin on, blue
  EXPECT_CALL(*_ledMock,
              readInput())
              .Times(3)
              .WillOnce(testing::Return(0x0))
              .WillOnce(testing::Return(0x1))
              .WillOnce(testing::Return(0x2));

  // printLedColor() prints to stdout using printf()
  testing::internal::CaptureStdout();  // capture stdiout
  printLedColor();                     // call function
  std::string output = testing::internal::GetCapturedStdout(); // gather stdout results
  EXPECT_EQ(output, "Red\n");  // check results

  testing::internal::CaptureStdout();
  printLedColor();
  output = testing::internal::GetCapturedStdout();
  std::cout << output << std::endl;
  EXPECT_EQ(output, "Green\n");

  testing::internal::CaptureStdout();
  printLedColor();
  output = testing::internal::GetCapturedStdout();
  std::cout << output << std::endl;
  EXPECT_EQ(output, "Blue\n");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
