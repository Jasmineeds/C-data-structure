#include <stdio.h>

int main()
{
  int L, S, count = 0;

  scanf("%d %d", &L, &S);

  while (S != L)
  {
    if (L > S)
    {
      S += 5;
      count++;
    }
    else if (S > L)
    {
      S -= 2;
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}
