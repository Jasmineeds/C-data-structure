#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int head, feet, rabbit, hen = 0;
  // input
  scanf("%d %d", &head, &feet);
  rabbit = head;
  while (rabbit * 4 + hen * 2 != feet && rabbit != 0)
  {
    rabbit--;
    hen++;
  }
  if (rabbit * 4 + hen * 2 == feet)
  {
    printf("YES\n%d %d\n", hen, rabbit);
  }
  else
  {
    printf("NO\n");
  }

  return 0;
}