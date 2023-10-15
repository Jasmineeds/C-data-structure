#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char input[50];
  int intCount = 0;
  int floatCount = 0;

  while (1)
  {
    scanf("%s", input);

    if (strcmp(input, "q") == 0)
    {
      break;
    }

    char *endPtr;
    double number = strtod(input, &endPtr);

    if (endPtr != input)
    {
      // int will be the same after conversion
      if ((double)(int)number == number)
      {
        intCount++;
      }
      else
      {
        floatCount++;
      }
    }
  }

  printf("%d\n", floatCount);
  printf("%d\n", intCount);

  return 0;
}
