#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num1, num2, num3, sum, product, min, max;
  double avg;

  // input
  scanf("%d %d %d", &num1, &num2, &num3);
  sum = num1 + num2 + num3;
  avg = (double)(num1 + num2 + num3) / 3;
  product = num1 * num2 * num3;

  // check min, max
  min = max = num1;

  if (num2 < min)
  {
    min = num2;
  }
  else if (num2 > max)
  {
    max = num2;
  }
  if (num3 < min)
  {
    min = num3;
  }
  else if (num3 > max)
  {
    max = num3;
  }

  // output
  printf("sum is %d\n", sum);
  printf("average is %.2lf\n", avg);
  printf("product is %d\n", product);
  printf("smallest is %d\n", min);
  printf("largest is %d\n", max);

  return 0;
}