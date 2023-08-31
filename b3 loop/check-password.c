#include <stdio.h>

int main()
{
  int password, input;

  scanf("%d", &password);

  if (password > 2000000000 || password < 1)
  {
    printf("Wrong Password Setting!\n");
    return 0;
  }
  else
  {
    scanf("%d", &input);
    while (input != password)
    {
      printf("Wrong Password!\n");
      scanf("%d", &input);
    }
    printf("Correct!\n");
  }

  return 0;
}
