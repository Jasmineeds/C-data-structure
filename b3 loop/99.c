#include <stdio.h>
int main()
{
  int height, width, i, j;

  scanf("%d", &height);
  scanf("%d", &width);
  for (i = 1; i <= height; i++)
  {
    for (j = 1; j <= width; j++)
    {
      printf("%d*%d=%2d ", i, j, i * j);
    }
    printf("\n");
  }

  return 0;
}