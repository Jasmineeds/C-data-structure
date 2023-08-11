#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int password;
  // input
  scanf("%d", &password);
  if (password % 7 == 0)
  {
    printf("YES\n");
    return 0;
  }

  while (password > 0)
  {
    if (password % 10 == 7)
    {
      printf("YES\n");
      return 0;
    }
    password /= 10;
  }

  printf("NO\n");

  return 0;
}