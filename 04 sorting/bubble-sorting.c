#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void print(int n, int *p)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", p[i]);
  }
}

int main()
{
  int data[5] = {34, 12, 5, 66, 1};
  int i, j;
  int n = 5;

  for (i = n; i > 1; i--)
  {
    for (j = 0; j < i - 1; j++)
    {
      if (data[j + 1] < data[j])
      {
        swap(&data[j + 1], &data[j]);
      }
    }
  }
  print(n, data);
  return 0;
}