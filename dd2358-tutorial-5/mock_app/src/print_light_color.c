#include <stdio.h>

#include "led_light.h"
#include "print_light_color.h"

void printLedColor()
{
  int idx = readInput();

  switch (idx) {
    case 0:
      printf("Red\n");
      break;
    case 1:
      printf("Green\n");
      break;
    case 2:
      printf("Blue\n");
      break;
    default:
      printf("Input Error!\n");
      break;
  }
}
