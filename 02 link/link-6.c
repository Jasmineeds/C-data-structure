#include <stdio.h>
#include <stdlib.h>

struct _node
{
  int num;
  struct _node *next;
};
typedef struct _node node;

// function: create new node
node *getnode()
{
  node *p;
  p = (node *)malloc(sizeof(node));
  if (p == NULL)
  {
    printf("記憶體不足");
    exit(1);
  }
  return p;
}

// function: free memory
void freenode(node *p)
{
  free(p);
}

// function: insert node
node *insertnode(node *head, node *ptr, node input)
{
  node *new_node;
  new_node = getnode();
  *new_node = input;
  new_node->next = NULL;

  if (ptr == NULL)
  {
    // case 1: first of the link
    new_node->next = head;
    head = new_node;
  }
  else
  {
    if (ptr->next == NULL)
    {
      // case 2: end of the link
      ptr->next = new_node;
    }
    else
    {
      // case 3: center of the link
      new_node->next = ptr->next;
      ptr->next = new_node;
    }
  }
  return head;
}

// function: print list
void printList(node *ptr)
{
  while (ptr != NULL)
  {
    printf("%d ", ptr->num);
    ptr = ptr->next;
  }
  puts("");
}

int main()
{
  node *head, *ptr;
  ptr = head = NULL;
  char op;
  node input;

  while (1)
  {
    scanf(" %c", &op);
    switch (op)
    {
    case 's':
      scanf("%d", &input.num);

      // first num or smaller than the first num
      if (head == NULL || head->num >= input.num)
      {
        head = insertnode(head, NULL, input);
      }
      else
      {
        ptr = head;
        // last num or middle num
        if (ptr->next == NULL || ptr->next->num >= input.num)
        {
          head = insertnode(head, ptr, input);
        }
        else
        {
          // middle num
          while (ptr->next != NULL && ptr->next->num < input.num)
          {
            ptr = ptr->next;
          }
          head = insertnode(head, ptr, input);
        }
      }
      break;
    case 'l':
      printList(head);
      break;
    case 'q':
      return 0;
      break;
    }
  }

  // release memory
  ptr = head;
  while (ptr != NULL)
  {
    node *nextNode = ptr->next;
    freenode(ptr);
    ptr = nextNode;
  }

  return 0;
}