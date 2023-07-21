#include <stdio.h>
#include <stdlib.h>

struct _node
{
  int data;
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
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  puts("");
}

// funciton: search node
node *find_node(node *head, int num)
{
  node *ptr;
  ptr = head;
  while (ptr != NULL)
  {
    if (ptr->data == num)
    {
      return ptr;
    }
    ptr = ptr->next;
  }
  return ptr;
}

// funciton: delete node
node *delete_node(node *head, node *ptr)
{
  node *previous;
  if (ptr == head)
  {
    head = head->next;
  }
  else
  {
    previous = head;
    while (previous->next != ptr)
    {
      previous = previous->next;
    }
    if (ptr->next == NULL)
    {
      previous->next = NULL;
    }
    else
    {
      previous->next = ptr->next;
    }
  }
  free(ptr);
  return head;
}

int main()
{
  node *head, *ptr;
  ptr = head = NULL;
  char op;
  node input;
  int num;

  while (1)
  {
    // puts("i insert");
    // puts("l list");
    // puts("q quit");
    // printf(">");

    scanf(" %c", &op);
    switch (op)
    {
    case 'i':
      scanf("%d", &input.data);
      if (head == NULL)
      {
        head = insertnode(head, NULL, input);
      }
      else
      {
        ptr = head;
        while (ptr->next != NULL)
        {
          ptr = ptr->next;
        }
        head = insertnode(head, ptr, input);
      }
      break;
    case 'l':
      printList(head);
      break;
    case 'f':
      scanf("%d", &num);
      ptr = find_node(head, num);
      if (ptr != NULL)
        printf("found %d\n", ptr->data);
      else
        printf("Not Found\n");
      break;
    case 'd':
      scanf("%d", &num);
      ptr = find_node(head, num);
      if (ptr != NULL)
      {
        head = delete_node(head, ptr);
        printf("Delete ok\n");
      }
      else
        printf("Can not delete\n");
      break;
    case 'q':
      return 0;
      break;
    }
    // system("pause");
    // system("cls");
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