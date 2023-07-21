#include <stdio.h>

// 定義遞迴函式計算階乘
int factorial(int n)
{
  if (n == 0)
  {
    return 1; // 當 n 為 0 時，階乘結果為 1
  }
  else
  {
    return n * factorial(n - 1); // 遞迴計算 n 的階乘
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  int result = factorial(n);
  printf("%d\n", result);

  return 0;
}
