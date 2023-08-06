#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6
#define MAX_STRING_LENGTH 20

void swap(char **a, char **b)
{
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void print(int n, char *p[])
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%s ", p[i]);
  }
}

// 將相鄰的資料兩兩比較大小，決定是否交換
void bubble_sort(char *data[], int n)
{
  int i, j;

  for (i = n; i > 1; i--)
  {
    for (j = 0; j < i - 1; j++)
    {
      if (strcmp(data[j + 1], data[j]) > 0)
      {
        swap(&data[j + 1], &data[j]);
      }
    }
    // print process
    for (int i = 0; i < N; i++)
    {
      printf("%s ", data[i]);
    }
    puts("");
  }
}

// 在一段資料中找出最大(小)值後，才做交換
void selection_sort(char *data[], int n)
{
  int i, j, max_index;

  for (i = 0; i < n - 1; i++)
  {
    max_index = i;
    for (j = i + 1; j < n; j++)
    {
      if (strcmp(data[j], data[max_index]) > 0)
        max_index = j;
    }
    if (max_index != i)
    {
      swap(&data[i], &data[max_index]);
    }

    // print process
    for (int i = 0; i < N; i++)
    {
      printf("%s ", data[i]);
    }
    puts("");
  }
}

// 將一段資料中最右(左)邊的資料當作key，然後往左(右)塞入 此資料中作排序。
void insertion_sort(char *data[], int n)
{
  int i, j;
  char *key;

  for (i = 1; i < n; i++)
  {
    key = data[i];
    j = i - 1;

    while (j >= 0 && strcmp(data[j], key) < 0)
    {
      data[j + 1] = data[j];
      j--;
    }

    data[j + 1] = key;
    // print process
    print(n, data);
    puts("");
  }
}

int main()
{
  int op;
  char *ary[N] = {0};
  int i;
  for (i = 0; i < N; i++)
  {
    ary[i] = (char *)malloc(MAX_STRING_LENGTH + 1);
    scanf("%20s", ary[i]);
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
  puts("");

  for (i = 0; i < N; i++)
  {
    free(ary[i]);
  }
}