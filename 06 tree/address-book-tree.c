#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binary_tree_node
{
  char name[100];
  char phone[20];
  struct binary_tree_node *left;
  struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

node *insert_node(node *root, node data)
{
  node *new_node;
  node *current;
  node *parent;

  new_node = (node *)malloc(sizeof(node));
  *new_node = data;
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
      if (strcmp(current->name, data.name) > 0)
      {
        current = current->left;
      }
      else
        current = current->right;
    }
    if (strcmp(parent->name, data.name) > 0)
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
    printf("Name: %s\n", ptr->name);
    printf("Phone: %s\n\n", ptr->phone);
    print_inorder(ptr->right);
  }
}

void print_preorder(node *ptr)
{
  if (ptr != NULL)
  {
    printf("Name: %s\n", ptr->name);
    printf("Phone: %s\n\n", ptr->phone);
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
    printf("Name: %s\n", ptr->name);
    printf("Phone: %s\n\n", ptr->phone);
  }
}

node *find_node(node *root, node data)
{
  if (root == NULL)
  {
    return NULL; // not found
  }

  if (strcmp(root->name, data.name) == 0)
  {
    return root; // found
  }
  else if (strcmp(root->name, data.name) > 0)
  {
    return find_node(root->left, data);
  }
  else
  {
    return find_node(root->right, data);
  }
}

node *find_parent(node *ptr, node data, int *pos)
{
  node *parent;

  parent = ptr;
  *pos = 0;
  while (ptr != NULL)
  {
    if (strcmp(ptr->name, data.name) == 0)
      return parent;
    else
    {
      parent = ptr;
      if (strcmp(ptr->name, data.name) > 0)
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

node *delete_node(node *root, node data)
{
  node *parent;
  node *ptr;
  node *next;
  int pos;

  // 找 value 的父節點
  parent = find_parent(root, data, &pos);
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
    *ptr = *next;
    if (parent == ptr)
      parent->left = next->left;
    else
      parent->right = next->left;
    free(next);
  }
  return root;
}

int main()
{
  int num;
  char op;
  node input;
  node *root = NULL;

  while (1)
  {
    scanf(" %c", &op);

    switch (op)
    {
    case 'i':
      scanf("%s", input.name);
      scanf("%s", input.phone);
      root = insert_node(root, input);
      break;
    case 'l':
      print_inorder(root);
      break;
    case 'm':
      print_preorder(root);
      break;
    case 'n':
      print_postorder(root);
      break;
    case 'f':
      scanf("%s", input.name);
      node *foundNode = find_node(root, input);
      if (foundNode == NULL)
        printf("not found");
      else
      {
        printf("found:\nName: %s\nPhone: %s\n", foundNode->name, foundNode->phone);
      }
      puts("");
      break;
    case 'd':
      scanf("%s", input.name);
      root = delete_node(root, input);
      printf("delete %s ok\n", input.name);
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