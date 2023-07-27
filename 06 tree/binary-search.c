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

node *search_node(node *ptr, int value)
{
  node *temp;

  if (ptr != NULL)
  {
    // 在這裡印出尋找比對過的資料
    printf("%d ", ptr->data);
    if (ptr->data == value)
      return ptr;
    else
    {
      temp = search_node(ptr->left, value);
      if (temp != NULL)
        return temp;
      temp = search_node(ptr->right, value);
      if (temp != NULL)
        return temp;
    }
  }
  return NULL;
}

int main()
{
  node *ptr;
  int value;

  // build tree
  node *root;
  // Level 1
  root = (node *)malloc(sizeof(node));
  root->data = 5;

  // Level 2
  root->left = (node *)malloc(sizeof(node));
  root->left->data = 4;
  root->left->left = NULL;
  root->left->right = NULL;

  root->right = (node *)malloc(sizeof(node));
  root->right->data = 6;
  root->right->left = NULL;
  root->right->right = NULL;

  // Level 3
  root->left->left = (node *)malloc(sizeof(node));
  root->left->left->data = 2;
  root->left->left->left = NULL;
  root->left->left->right = NULL;

  root->right->right = (node *)malloc(sizeof(node));
  root->right->right->data = 8;
  root->right->right->left = NULL;
  root->right->right->right = NULL;

  // Level 4
  root->left->left->left = (node *)malloc(sizeof(node));
  root->left->left->left->data = 1;
  root->left->left->left->left = NULL;
  root->left->left->left->right = NULL;

  root->left->left->right = (node *)malloc(sizeof(node));
  root->left->left->right->data = 3;
  root->left->left->right->left = NULL;
  root->left->left->right->right = NULL;

  root->right->right->left = (node *)malloc(sizeof(node));
  root->right->right->left->data = 7;
  root->right->right->left->left = NULL;
  root->right->right->left->right = NULL;

  root->right->right->right = (node *)malloc(sizeof(node));
  root->right->right->right->data = 9;
  root->right->right->right->left = NULL;
  root->right->right->right->right = NULL;

  // search
  scanf("%d", &value);
  ptr = search_node(root, value);
  puts("");
  if (ptr != NULL)
  {
    printf("found %d\n", ptr->data);
  }
  else
  {
    puts("not found");
  }
  return 0;
}