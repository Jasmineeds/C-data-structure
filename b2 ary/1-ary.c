#include <stdio.h>
#define N 5

void sort(int *ary)
{
  int i, j;
  int tmp;

  for (i = 0; i < N - 1; i++)
  {
    for (j = 0; j < N - 1 - i; j++)
    {
      if (ary[j] > ary[j + 1])
      {
        tmp = ary[j];
        ary[j] = ary[j + 1];
        ary[j + 1] = tmp;
      }
    }
  }
}

int main()
{
  int i, j, a[N];

  // input
  for (i = 0; i < N; i++)
  {
    scanf("%d", &a[i]);
  }

  // sort
  sort(a);

  // output
  for (i = 0; i < N; i++)
  {
    printf("%d\t", a[i]);
    for (j = 0; j < a[i]; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}