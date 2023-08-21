#include <stdio.h>

int main()
{
  int H, W;
  int i, j;

  scanf("%d %d", &H, &W);
  int ary[H][W];

  for (i = 0; i < H; i++)
  {
    for (j = 0; j < W; j++)
    {
      scanf("%d", &ary[i][j]);
    }
  }

  // regular
  for (i = 0; i < H; i++)
  {
    for (j = 0; j < W; j++)
    {
      printf("%5d", ary[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // flip
  for (i = 0; i < W; i++)
  {
    for (j = 0; j < H; j++)
    {
      printf("%5d", ary[j][i]);
    }
    printf("\n");
  }
  printf("\n");

  // flip 2
  for (i = W - 1; i >= 0; i--)
  {
    for (j = H - 1; j >= 0; j--)
    {
      printf("%5d", ary[j][i]);
    }
    printf("\n");
  }
  printf("\n");

  // flip 3
  for (i = H - 1; i >= 0; i--)
  {
    for (j = W - 1; j >= 0; j--)
    {
      printf("%5d", ary[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // flip 4
  for (i = 0; i < W; i++)
  {
    for (j = H - 1; j >= 0; j--)
    {
      printf("%5d", ary[j][i]);
    }
    printf("\n");
  }
  printf("\n");

  // flip 5
  for (i = W - 1; i >= 0; i--)
  {
    for (j = 0; j < H; j++)
    {
      printf("%5d", ary[j][i]);
    }
    printf("\n");
  }

  return 0;
}