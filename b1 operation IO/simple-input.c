#include <stdio.h>
#include <stdlib.h>

int main()
{
  char name[20]; // for user input
  int num1 = 20, score1 = 40;
  int num2 = 21, score2 = 100;

  scanf("%s", name);

  printf("姓名\t座號\t分數\n");
  printf("王小明\t%d\t%d\n", num1, score1);
  printf("%s\t%d\t%d\n", name, num2, score2);

  return 0;
}
