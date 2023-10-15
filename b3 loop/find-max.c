#include <stdio.h>

int main()
{
  int N;

  // number count
  scanf("%d", &N);

  if (N <= 0)
  {
    return 1;
  }

  int maxVal = 0;
  int minVal = 0;
  int maxPos = 0;
  int minPos = 0;

  for (int i = 1; i <= N; i++)
  {
    int num;

    scanf("%d", &num);

    if (num > maxVal || i == 1)
    {
      maxVal = num;
      maxPos = i;
    }

    if (num < minVal || i == 1)
    {
      minVal = num;
      minPos = i;
    }
  }

  printf("%d %d\n", maxVal, maxPos);
  printf("%d %d\n", minVal, minPos);

  return 0;
}
