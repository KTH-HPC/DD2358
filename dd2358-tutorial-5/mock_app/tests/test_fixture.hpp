#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {

#include "print_light_color.h"
#include "led_light.h"

}

class LEDMock {
public:
  virtual ~LEDMock(){}
  // define the functions we mock with MOCK_METHOD*, where * is the number of arguments
  MOCK_METHOD0(readPins, uint8_t());
  MOCK_METHOD0(readInput, int());
};

class LEDUnitTest : public ::testing::Test
{
public:
  LEDUnitTest()
  {
    // init the mock object
    _ledMock.reset(new ::testing::NiceMock<LEDMock>());
  }
  
  ~LEDUnitTest()
  {
  // free the mock object
  _ledMock.reset();
  }

  virtual void SetUp(){}
  virtual void TearDown(){}
  
  static std::unique_ptr<LEDMock> _ledMock;
};

// singleton
std::unique_ptr<LEDMock> LEDUnitTest::_ledMock;
