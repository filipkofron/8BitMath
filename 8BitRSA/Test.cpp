#include "UInt512.h"
#include <cstdlib>

void main(void)
{
  UInt512 num;
  num.DebugPrint();

  UInt512 num2(123456);
  UInt512 num3(654321);
  UInt512 num4(num3 - num2);
  num4.DebugPrint();

  system("pause");
}