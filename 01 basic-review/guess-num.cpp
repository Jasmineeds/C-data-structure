#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int ans;
  int guess;
  int min = 1, max = 100;

  scanf("%d", &ans);

  while (1)
  {
    printf("%d < ? < %d\n", min, max);
    scanf("%d", &guess);

    if (guess <= min || guess >= max)
    {
      printf("out of range\n");
      continue;
    }
    else if (guess < ans)
    {
      printf("wrong answer, guess larger\n");
      min = guess;
      continue;
    }
    else if (guess > ans)
    {
      printf("wrong answer, guess smaller\n");
      max = guess;
      continue;
    }
    else
    {
      printf("bingo answer is %d\n", ans);
      break;
    }
  }

  return 0;
}
