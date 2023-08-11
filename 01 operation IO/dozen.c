#include <stdio.h>

int main()
{
  int num, dozen, remain;

  scanf("%d", &num);
  dozen = num / 12;
  remain = num % 12;

  if (remain == 0)
    printf("%d dozen\n", dozen);
  else
    printf("%d dozen and %d\n", dozen, remain);

  return 0;
}
