#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tree {
  int data;
  struct tree *left, *right;
};

struct tree* create(int val) {
  struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct tree* insertTo (struct tree *root, int pos, int val) {
  if (root == NULL) {
    struct tree *tmp = (struct tree*)malloc(sizeof(struct tree));
    tmp = create(val);
    root = tmp;
  }
  // else {
  //   if (pos == 1)
  //     insertTo(root->left, 1, val);
  //   else if(pos == 2)
  //     insertTo(root->right, 2, val);
  // }

  if (pos == 1 && root->left == NULL) {
    root->left = (struct tree *)malloc(sizeof(struct tree));
    root->left = create(val);
    return root->left;
  }

  if (pos == 1 && root->left != NULL) {
    insertTo(root->left, 1, val);
  }

   if (pos == 2 && root->right == NULL) {
    root->right = (struct tree *)malloc(sizeof(struct tree));
    root->right = create(val);
    return root->right;
  }

  if (pos == 2 && root->right != NULL) {
    insertTo(root->right, 2, val);
  }
  printf("\nSuccess!");
}

void insert (struct tree *root) {
  int pos, val;
  printf("\nEnter value:");
  scanf("%d", &val);
  printf("\nEnter the branch (1:Left, 2:Right): ");
  scanf("%d", &pos);
  if (pos !=1 && pos != 2)
    printf("\nInvalid entry.");
  else {
    // if (pos == 1)
    //   insertTo(root->left, 1, val);
    // else if(pos == 2)
    //   insertTo(root->right, 2, val);
    insertTo(root, pos, val);
  }
}

void display_err(struct tree *root) {
  struct tree *tempL, *tempR;
  tempL = root;
  tempR = root;
  while(tempL != NULL) {
    printf("%d", tempL->data);
    tempL = tempL->left;
  }
  while (tempR != NULL) {
    printf("%d", tempR->data);
    tempR = tempR->right;
  }
}

void display(struct tree* head) {
  struct tree *root = head;
  if (root == NULL)
    return;
  else {
    display(root->left);
    printf("%d\t", &root->data);
    display(root->right);
  }
}

struct tree* inOrder(struct tree *leaf) {
  if (leaf == NULL)
    return NULL;
  else {
    inOrder(leaf->left);
    printf("%d ", leaf->data);
    inOrder(leaf->right);
  }
}

int main() {
  int c, val;
  struct tree *root = (struct tree*)malloc(sizeof(struct tree*));
  while (1) {
    printf("\nBinary Tree");
    printf("\n1. Create\n2. Insert \n3. Delete \n4. Display \n0. Quit \nYour choice: ");
    scanf("%d", &c);
    switch (c) {
      case 0:
        return 0;
      case 1:
        printf("\nEnter data: ");
        scanf("%d", &val);
        root = create(val);
        break;
      case 2:
        insert(root);
        break;
      case 3:
        break;
      case 4:
        inOrder(root);
        break;
      default:
        break;
    }  
  }
}