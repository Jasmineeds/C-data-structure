// '' 跟 "" 的差別：一個是給字元的，一個是給字串的．字元可以像數字一樣做比對跟運算
#include <stdio.h>

int main()
{
  int score;
  char iscontinue = 'y';

  while (iscontinue == 'y')
  {
    scanf("%d", &score);
    if (score < 60)
    {
      printf("fail\n");
    }
    else
    {
      printf("pass\n");
    }
    scanf(" %c", &iscontinue);
  }

  return 0;
}