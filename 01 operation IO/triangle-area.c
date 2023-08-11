#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double p1x, p1y, p2x, p2y, p3x, p3y;
  double a, b, c, s, area;

  // input
  scanf("%lf %lf", &p1x, &p1y);
  scanf("%lf %lf", &p2x, &p2y);
  scanf("%lf %lf", &p3x, &p3y);

  a = sqrt(pow((p2x - p1x), 2) + pow((p2y - p1y), 2));
  b = sqrt(pow((p3x - p2x), 2) + pow((p3y - p2y), 2));
  c = sqrt(pow((p1x - p3x), 2) + pow((p1y - p3y), 2));

  s = (a + b + c) / 2;
  area = sqrt(s * (s - a) * (s - b) * (s - c));

  // output
  printf("%.2lf\n", area);

  return 0;
}