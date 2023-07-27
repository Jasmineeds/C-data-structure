#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binary_tree_node
{
  int data;
  struct binary_tree_node *left;
  struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

node *insert_node(node *root, int value)
{
  node *new_node;
  node *current;
  node *parent;

  new_node = (node *)malloc(sizeof(node));
  new_node->data = value;
  new_node->right = NULL;
  new_node->left = NULL;
  if (root == NULL)
  {
    root = new_node;
  }
  else
  {
    current = root;
    while (current != NULL)
    {
      parent = current;
      if (current->data > value)
      {
        current = current->left;
      }
      else
        current = current->right;
    }
    if (parent->data > value)
      parent->left = new_node;
    else
      parent->right = new_node;
  }
  return root;
}

void print_inorder(node *ptr)
{
  if (ptr != NULL)
  {
    print_inorder(ptr->left);
    printf("%d ", ptr->data);
    print_inorder(ptr->right);
  }
}

void print_preorder(node *ptr)
{
  if (ptr != NULL)
  {
    printf("%d ", ptr->data);
    print_preorder(ptr->left);
    print_preorder(ptr->right);
  }
}

void print_postorder(node *ptr)
{
  if (ptr != NULL)
  {
    print_postorder(ptr->left);
    print_postorder(ptr->right);
    printf("%d ", ptr->data);
  }
}

int main()
{
  int num;
  char op;
  node *root = NULL;

  while (1)
  {
    scanf(" %c", &op);

    switch (op)
    {
    case 'i':
      scanf("%d", &num);
      root = insert_node(root, num);
      break;
    case 'l':
      print_inorder(root);
      puts("");
      break;
    case 'm':
      print_preorder(root);
      puts("");
      break;
    case 'n':
      print_postorder(root);
      puts("");
      break;
    case 'q':
      return 0;
    default:
      printf("Please try again.\n");
      break;
    }
  }

  return 0;
}