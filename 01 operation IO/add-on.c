#include <stdio.h>

int main()
{
  int N, sum = 0;

  scanf("%d", &N);

  for (int i = 0; i < 4; i++)
  {
    sum += N % 10; // get last digit
    N /= 10;       // cut last digit
  }

  printf("%d\n", sum);

  return 0;
}
