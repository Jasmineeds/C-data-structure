// 使用動態記憶體配置
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hanoi(int n, char from, char mid, char to, int *ct)
{
  if (n == 0)
    return;
  // 先把 n-1 的盤子搬到中間
  hanoi(n - 1, from, to, mid, ct);
  // 把自己搬到尾端
  printf("plate %d from %c -> %c\n", n, from, to);
  ct[n - 1]++;
  // 再把 n-1 的盤子從中間搬回來
  hanoi(n - 1, mid, from, to, ct);
}

// void *calloc(size_t num, size_t size)
// {
//   char *str1 = (char *)calloc(num, size);
//   char *str2 = (char *)malloc(num * size);
//   memset(str2, 0, 20);
// }

int main()
{
  int n, i;
  scanf("%d", &n);
  int *ct = (int *)malloc(sizeof(int) * n);
  memset(ct, 0, sizeof(int) * n);

  hanoi(n, 'A', 'B', 'C', ct);
  puts("");
  for (int i = 0; i < n; i++)
  {
    printf("plate %d = %d\n", i + 1, ct[i]);
  }

  free(ct);

  return 0;
}