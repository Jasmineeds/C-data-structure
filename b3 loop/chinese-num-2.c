#include <stdio.h>

const char *digits[] = {"", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖"};
const char *units[] = {"", "拾", "佰", "仟", "萬"};

int main()
{
  int num;
  char ans[100] = "";

  scanf("%d", &num);

  if (num > 99999 || num < 1)
  {
    printf("out of range");
    return 0;
  }
  else
  {
    int unitIndex = 0;
    while (num > 0)
    {
      int digit = num % 10;
      if (digit != 0)
      {
        const char *digitStr = digits[digit];
        const char *unitStr = units[unitIndex];
        sprintf(ans, "%s%s%s", digitStr, unitStr, ans);
      }
      unitIndex++;
      num /= 10;
    }
    printf("%s元整", ans);
  }

  return 0;
}
