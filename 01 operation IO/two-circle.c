#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double r1, r2, sub;
  double PI = 3.141592653589793;
  // input
  scanf("%lf %lf", &r1, &r2);
  sub = (pow(r2, 2) - pow(r1, 2)) * PI;

  // output
  printf("%.2lf", sub);
  return 0;
}