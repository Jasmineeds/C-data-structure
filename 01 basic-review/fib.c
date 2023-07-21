#include <stdio.h>
#include <stdlib.h>

int fib(int n, int ct[])
{
  if (n == 1 || n == 2)
    return 1;

  if (ct[n - 1])
    return ct[n - 1];

  int a = fib(n - 1, ct);
  int b = fib(n - 2, ct);
  ct[n - 1] = a + b;
  return a + b;
}

int main()
{
  int n;
  scanf("%d", &n);
  int *ct = (int *)malloc(n * sizeof(int));
  if (ct == NULL)
  {
    printf("動態記憶體配置失敗\n");
    return 1;
  }

  printf("%d", fib(n, ct));

  free(ct);
  return 0;
}
