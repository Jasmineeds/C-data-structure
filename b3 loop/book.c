#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char friendBook[100];
  char libraryBook[100];
  int bookCount = 0;
  int bookNumber = 0;
  int found = 0;

  scanf("%s", friendBook);

  while (1)
  {
    scanf("%s", libraryBook);
    if (strcmp(libraryBook, "q") == 0)
      break;

    bookCount++;

    // to lowercase
    for (int i = 0; i < strlen(friendBook); i++)
    {
      friendBook[i] = tolower(friendBook[i]);
    }
    for (int i = 0; i < strlen(libraryBook); i++)
    {
      libraryBook[i] = tolower(libraryBook[i]);
    }

    // compare
    if (strcmp(friendBook, libraryBook) == 0)
    {
      found = 1;
      bookNumber = bookCount;
    }
  }

  if (found)
  {
    printf("Yes %d\n", bookNumber);
  }
  else
  {
    printf("No %d\n", bookCount);
  }

  return 0;
}
