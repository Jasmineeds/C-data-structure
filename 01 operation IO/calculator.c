#include <stdio.h>
#include <stdlib.h>

int main()
{
  double num1, num2, add, sub, mul, div;
  // input
  scanf("%lf %lf", &num1, &num2);
  add = num1 + num2;
  sub = num1 - num2;
  mul = num1 * num2;
  div = num1 / num2;
  // output
  printf("%.2lf + %.2lf = %.2lf\n", num1, num2, add);
  printf("%.2lf - %.2lf = %.2lf\n", num1, num2, sub);
  printf("%.2lf * %.2lf = %.2lf\n", num1, num2, mul);
  printf("%.2lf / %.2lf = %.2lf\n", num1, num2, div);
  return 0;
}