#include <stdio.h>
#include <stdlib.h>

int com(int n, int m, int **ct)
{
  if (m == 0 || m == n)
    return 1;

  if (ct[n - 1][m - 1])
    return ct[n - 1][m - 1];

  int result = com(n - 1, m, ct) + com(n - 1, m - 1, ct);
  ct[n - 1][m - 1] = result;
  return result;
}

int main()
{
  int numN, numM;
  scanf("%d%d", &numN, &numM);

  if (numN < numM)
  {
    printf("input error");
    return 0;
  }

  int **ct = (int **)malloc(numN * sizeof(int *));
  for (int i = 0; i < numN; i++)
  {
    ct[i] = (int *)malloc(numM * sizeof(int));
    for (int j = 0; j < numM; j++)
    {
      ct[i][j] = 0;
    }
  }

  // print
  printf("%d", com(numN, numM, ct));

  free(ct);
  return 0;
}