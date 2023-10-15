#include <stdio.h>

void printNumber(int num)
{
  const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  const char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  const char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  if (num >= 1 && num <= 9)
  {
    printf("%s ", ones[num]);
  }
  else if (num >= 11 && num <= 19)
  {
    printf("%s ", teens[num - 10]);
  }
  else if (num >= 10 && num <= 90 && num % 10 == 0)
  {
    printf("%s ", tens[num / 10]);
  }
}

int main()
{
  int amount;

  scanf("%d", &amount);

  if (amount < 1 || amount > 9999999)
  {
    return 1;
  }

  // 處理百萬位數
  if (amount >= 1000000)
  {
    int millions = amount / 1000000;
    printNumber(millions);
    printf("million ");
    amount %= 1000000;
  }

  // 處理千位數
  if (amount >= 1000)
  {
    int thousands = amount / 1000;
    printNumber(thousands);
    printf("thousand ");
    amount %= 1000;
  }

  // 處理百位數
  if (amount >= 100)
  {
    int hundreds = amount / 100;
    printNumber(hundreds);
    printf("hundred ");
    amount %= 100;
  }

  // 處理十位數和個位數
  if (amount > 0)
  {
    printNumber(amount);
  }

  printf("dollar%s\n", (amount == 1) ? "" : "s");

  return 0;
}
