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
  ptr = head;
  // printf("head => %d\n", head);
  // printf("ptr => %d\n", ptr);
  int value;
  int i;
  int n = 5;

  for (i = 0; i < n; i++)
  {
    // value = (i + 1) * 10;
    scanf("%d", &value);
    ptr->data = value;
    if (i < n - 1)
    {
      ptr->next = (node *)malloc(sizeof(node));
      ptr = ptr->next;
      // printf("ptr => %d\n", ptr);
    }
    else
    {
      ptr->next = NULL;
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