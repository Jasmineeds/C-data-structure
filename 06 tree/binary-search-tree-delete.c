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

node *find_node(node *root, int value)
{
  if (root == NULL)
  {
    return NULL; // not found
  }

  if (root->data == value)
  {
    return root; // found
  }
  else if (value < root->data)
  {
    return find_node(root->left, value);
  }
  else
  {
    return find_node(root->right, value);
  }
}

node *find_parent(node *ptr, int value, int *pos)
{
  node *parent;

  parent = ptr;
  *pos = 0;
  while (ptr != NULL)
  {
    if (ptr->data == value)
      return parent;
    else
    {
      parent = ptr;
      if (ptr->data > value)
      {
        *pos = -1;
        ptr = ptr->left;
      }
      else
      {
        *pos = 1;
        ptr = ptr->right;
      }
    }
  }
  return NULL; // not found
}

node *delete_node(node *root, int value)
{
  node *parent;
  node *ptr;
  node *next;
  int pos;

  // 找 value 的父節點
  parent = find_parent(root, value, &pos);
  if (parent != NULL)
  {
    switch (pos) // 判斷目前結點在父節點的左邊或右邊，還原 ptr 的位置
    {
    case -1:
      ptr = parent->left;
      break;
    case 1:
      ptr = parent->right;
      break;
    case 0:
      ptr = parent;
      break;
    }
  }
  // case1: 節點沒有左子樹
  if (ptr->left == NULL)
  {
    if (parent == ptr)
      root = root->right;
    else
    {
      if (pos == 1)
      {
        parent->right = ptr->right;
      }
      else
      {
        parent->left = ptr->right;
      }
    }
    free(ptr);
  }
  // case2: 節點沒有右子樹
  else if (ptr->right == NULL)
  {
    // case2-1: 節點是不是 root？可以用 parent==ptr, parent==root, pos==0 來判斷
    if (parent != ptr)
    {
      // case2-2: 節點在右邊
      if (pos == 1)
      {
        parent->right = ptr->left; // 連起來
      }
      // case2-3: 節點在左邊
      else
      {
        parent->left = ptr->left; // 連起來
      }
    }
    else
      root = root->left;
    free(ptr);
  }
  // case3: 節點有左右子樹
  else
  {
    parent = ptr;
    next = ptr->left;
    while (next->right != NULL)
    {
      parent = next;
      next = next->right;
    }
    ptr->data = next->data;
    if (parent == ptr)
      parent->left = next->left;
    else
      parent->right = next->left;
    free(next);
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
    case 'f':
      scanf("%d", &num);
      node *foundNode = find_node(root, num);
      if (foundNode == NULL)
        printf("not found");
      else
      {
        printf("found: %d", foundNode->data);
      }
      puts("");
      break;
    case 'd':
      scanf("%d", &num);
      root = delete_node(root, num);
      printf("delete %d ok", num);
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