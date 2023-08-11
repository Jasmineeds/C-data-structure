#include <stdio.h>
#include <stdlib.h>

int main()
{
  int time, heat, cool, ans, basic = 20;

  // input
  scanf("%d %d %d", &time, &heat, &cool);

  if (time % 2 == 1 || time == 1)
  {
    ans = basic + heat * ((time / 2) + 1) - cool * (time / 2);
  }
  else if (time % 2 == 0 && time != 0)
  {
    ans = basic + heat * (time / 2) - cool * ((time / 2) - 1);
  }
  else
  {
    ans = basic;
  }

  // output
  printf("%d\n", ans);

  return 0;
}