#include <stdio.h>
#include <stdlib.h>
#define N 6

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

void bubble_sort(int data[], int n)
{
  int i, j;

  for (i = n; i > 1; i--)
  {
    for (j = 0; j < i - 1; j++)
    {
      if (data[j + 1] < data[j])
      {
        swap(&data[j + 1], &data[j]);
      }
    }
    // print process
    for (int i = 0; i < N; i++)
    {
      printf("%d ", data[i]);
    }
    puts("");
  }
}

void selection_sort(int data[], int n)
{
  int i, j;
  int *min, *pos;

  for (i = 0; i < n - 1; i++)
  {
    min = data + i;
    for (j = i + 1; j < n; j++)
    {
      pos = &data[j];
      if (*pos < *min)
        min = pos;
    }
    swap(&data[i], min);
    // print process
    for (int i = 0; i < N; i++)
    {
      printf("%d ", data[i]);
    }
    puts("");
  }
}

void insertion_sort(int data[], int n)
{
  int i, j;
  int key;
  int *cur, *keyp;
  for (i = 1; i < n; i++)
  {
    key = data[i];
    keyp = &data[i];
    for (j = i - 1; j >= 0 && data[j] > key; j--)
    {
      cur = &data[j];
      data[j + 1] = data[j];
      cur = &data[j + 1];
    }
    data[j + 1] = key;
    // print process
    for (int i = 0; i < N; i++)
    {
      printf("%d ", data[i]);
    }
    puts("");
  }
}

int main()
{
  int op;
  int ary[N];
  int i;
  for (i = 0; i < N; i++)
  {
    scanf("%d", ary + i);
  }

  scanf("%d", &op);
  switch (op)
  {
  case 1:
    bubble_sort(ary, N);
    break;
  case 2:
    selection_sort(ary, N);
    break;
  case 3:
    insertion_sort(ary, N);
    break;
  default:
    printf("Please try again.");
    break;
  }
  print(N, ary);
}