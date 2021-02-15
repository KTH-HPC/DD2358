#include "pin_io.h"
#include "led_light.h"

int readInput()
{
  uint8_t num = readPins();
  int ret = -1;

  for (int i = 0; i < NUM_PINS; i++) {
    if ((num >> i) & 1) {
      ret = i;
      break;
    }
  }

  return ret;
}
