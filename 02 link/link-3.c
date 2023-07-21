#include <stdio.h>
#include <stdlib.h>

struct _node
{
  int data;
  struct _node *next;
};
typedef struct _node node;

int main()
{
  node *head, *ptr, *p4d;
  int value;
  head = NULL;

  while (1)
  {
    scanf("%d", &value);
    if (value == -1)
      break;
    if (head == NULL)
    {
      head = (node *)malloc(sizeof(node));
      head->data = value;
      head->next = NULL;
      ptr = head;
    }
    else
    {
      head = (node *)malloc(sizeof(node));
      head->data = value;
      head->next = ptr;
      ptr = head;
    }
  }

  // print
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  puts("");

  // release
  ptr = head;
  while (ptr != NULL)
  {
    p4d = ptr->next;
    free(ptr);
    ptr = p4d;
  }

  return 0;
}