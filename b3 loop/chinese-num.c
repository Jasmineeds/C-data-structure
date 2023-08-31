#include <stdio.h>
#include <string.h>

const char *convertCH(int num)
{
  static const char *chineseNumbers[] = {
      "", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖"};

  return (num > 0 && num <= 9) ? chineseNumbers[num] : "wrong";
}

int main()
{
  int num;
  char ans[100] = "";
  char temp[100]; // for temp string

  scanf("%d", &num);

  if (num > 99999 || num < 1)
  {
    printf("out of range\n");
    return 0;
  }
  else
  {
    while (num > 0)
    {
      if (num >= 10000)
      {
        sprintf(temp, "%s%s%s", ans, convertCH(num / 10000 % 10), "萬");
        strcpy(ans, temp);
        num %= 10000;
      }
      else if (num >= 1000)
      {
        sprintf(temp, "%s%s%s", ans, convertCH(num / 1000 % 10), "仟");
        strcpy(ans, temp);
        num %= 1000;
      }
      else if (num >= 100)
      {
        sprintf(temp, "%s%s%s", ans, convertCH(num / 100 % 10), "佰");
        strcpy(ans, temp);
        num %= 100;
      }
      else if (num >= 10)
      {
        sprintf(temp, "%s%s%s", ans, convertCH(num / 10 % 10), "拾");
        strcpy(ans, temp);
        num %= 10;
      }
      else
      {
        sprintf(temp, "%s%s", ans, convertCH(num));
        strcpy(ans, temp);
        num = 0;
      }
    }
    printf("%s元整\n", ans);
  }

  return 0;
}
