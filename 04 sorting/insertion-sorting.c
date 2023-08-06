#include <stdio.h>
#include <stdlib.h>

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
  int key; // 紀錄要被插入的值
  int *cur, *keyp;
  int n = 5;
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
    data[j + 1] = key; // 將 key 插入
  }

  print(n, data);
  return 0;
}

// int main()
// {
//   int data[5] = {34, 12, 5, 66, 1};
//   int i, j;
//   int key; // 紀錄要被插入的值
//   int n = 5;
//   for (i = 1; i < n; i++)
//   {
//     key = data[i];
//     for (j = i - 1; j >= 0 && data[j] > key; j--)
//     {
//       data[j + 1] = data[j];
//     }
//     data[j + 1] = key; // 將 key 插入
//   }

//   print(n, data);
//   return 0;
// }