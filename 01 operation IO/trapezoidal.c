#include <stdio.h>
#include <stdlib.h>

int main()
{
  int top, base, height;
  scanf("%d", &top);
  scanf("%d", &base);
  scanf("%d", &height);
  double area = (double)(top + base) * height / 2;
  printf("%.1f", area);
  return 0;
}