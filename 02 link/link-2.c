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
  node *head, *ptr;
  head = (node *)malloc(sizeof(node));

  // printf("head => %d\n", head);
  // printf("ptr => %d\n", ptr);
  int value;

  scanf("%d", &value);
  head->data = value;
  head->next = NULL;
  ptr = head;

  while (ptr != NULL)
  {
    scanf("%d", &value);
    if (value != -1)
    {
      ptr->next = (node *)malloc(sizeof(node));
      ptr = ptr->next;
      ptr->data = value;
      ptr->next = NULL;
      // printf("ptr => %d\n", ptr);
    }
    else
    {
      ptr = ptr->next;
    }
  }

  ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  return 0;
}