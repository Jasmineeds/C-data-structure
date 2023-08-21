#include <stdio.h>
#include <stdlib.h>

int main()
{
  char name[20], gender[20];
  int age;

  scanf("%s %d %s", name, &age, gender);

  printf("Name:%s\n", name);
  printf("Age:%d\n", age);
  printf("Gender:%s\n", gender);

  return 0;
}