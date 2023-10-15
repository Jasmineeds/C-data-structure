#include <stdio.h>

int isPrime(int num)
{
  if (num <= 1)
  {
    return 0;
  }

  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return 0;
    }
  }

  return 1;
}

int main()
{
  int m;

  scanf("%d", &m);

  for (int i = 2; i <= m; i++)
  {
    if (isPrime(i))
    {
      printf("%d is prime\n", i);
    }
  }

  return 0;
}
