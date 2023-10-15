#include <stdio.h>

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);

  int items[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &items[i]);
  }

  int totalItems = 0;
  int totalVolume = 0;

  for (int i = 0; i < N; i++)
  {
    if (items[i] <= K)
    {
      totalVolume += items[i];
      totalItems++;
    }
  }

  printf("%d %d\n", totalItems, totalVolume);

  return 0;
}
