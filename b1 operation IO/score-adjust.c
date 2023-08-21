#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double original, adjusted;
  int gap;
  // input
  scanf("%lf", &original);
  adjusted = sqrt(original) * 10;
  gap = round(adjusted - original);

  // output
  printf("Original: %.2lf\n", original);
  printf("Adjusted: %.2lf(+%d)\n", adjusted, gap);
  return 0;
}