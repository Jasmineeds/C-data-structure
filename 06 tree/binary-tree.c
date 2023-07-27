#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define
struct binary_tree_node
{
  int data;
  struct binary_tree_node *left;
  struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

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

// main function
int main()
{
  node *root;

  // Level 1
  root = (node *)malloc(sizeof(node));
  root->data = 5;
  root->left = NULL;
  root->right = NULL;

  // Level 2
  root->left = (node *)malloc(sizeof(node));
  root->left->data = 4;
  root->left->left = NULL;
  root->left->right = NULL;
  root->right = (node *)malloc(sizeof(node));
  root->right->data = 6;
  root->right->left = NULL;
  root->right->right = NULL;

  print_preorder(root);
  puts("");
  print_inorder(root);
  puts("");
  print_postorder(root);
  puts("");
  return 0;
}