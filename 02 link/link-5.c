#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _node
{
  char name[128];
  int phone;
  char email[128];
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
    printf("%s\n", ptr->name);
    printf("%s\n", ptr->email);
    printf("%010d\n", ptr->phone);
    puts("");
    ptr = ptr->next;
  }
}

// funciton: search node
node *find_node(node *head, char name[])
{
  node *ptr;
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(ptr->name, name) == 0)
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
  char name[128];

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
      scanf("%s", input.name);
      scanf("%s", input.email);
      scanf("%d", &input.phone);
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
      scanf("%s", name);
      ptr = find_node(head, name);
      if (ptr != NULL)
      {
        printf("found\n");
        printf("%s\n", ptr->name);
        printf("%s\n", ptr->email);
        printf("%010d\n", ptr->phone);
        puts("");
      }
      else
        printf("Not Found\n");
      break;
    case 'd':
      scanf("%s", name);
      ptr = find_node(head, name);
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