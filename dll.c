#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next, *prev;
};

typedef struct node list;

list *newNode(int val) {
  list *temp = (list *)malloc(sizeof(list));
  temp->data = val;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

void append(list *dll, int val) {
  list *temp = dll;
  while (temp->next != NULL)
    temp = temp->next;
  list *new = newNode(val);
  new->prev = temp;
  temp->next = new;
}

void insert(list *temp, int pos, int val) {
  while (temp->next != NULL && temp->data != pos)
    temp = temp->next;
  if (temp->data == pos) {
    list *toInsert = newNode(val);
    toInsert->prev = temp;
    toInsert->next = temp->next;
    temp->next->prev = toInsert;
    temp->next = toInsert;
  }
  else {
    printf("\n Element not found.");
  }
}

void pop(list* root) {
  list *temp = root;
  for (; temp->next != NULL; temp=temp->next){}
  temp->prev->next = NULL;
  printf("%d is popped.", temp->data);
  free(temp);
}

list* search(list *root, int key) {
  list *temp;
  for (temp = root; temp->next != NULL && temp -> data != key; temp = temp->next) {}
  if (temp ->data == key) {
    printf("%d is found.", temp->data);
    return temp;
  }
  else {
    printf("%d is not found. ", key);
    return NULL;
  }
}

void delete(list *dll, int key) {
  list *nd = search(dll, key);
  if (nd == NULL)
    return;
  else {
    nd->prev->next = nd->next;
    nd->next->prev = nd->prev;
    printf("\nSuccesfully deleted.");
    free(nd);
  }
}

void display(list* root) {
  list *temp = root;
  if (root == NULL)
    printf("Empty list");
  for (; temp != NULL; temp = temp->next) {
    printf("%d", temp->data);
    if (temp->next != NULL)
      printf(", ");
    else
      printf(".");
  }
}

list *create() {
  int t, i, val;
  printf("\nEnter a value: ");
  scanf("%d", &val);
  list *temp = newNode(val);
  printf("\nHow many more elements do you want to add? ");
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    printf("\nEnter a value to insert: ");
    scanf("%d", &val);
    append(temp, val);
  }
  return temp;
}

int main() {
  int ch, val, pos;
  list *root;
  while (1) {
    printf("\n\nDOUBLY LINKED LIST \n1. Create \n2. Append \n3. Insert \n4. Pop \n5. Delete \n6. Search \n7. Display \n0. Quit \nYour choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      root = create();
      break;
    case 2:
      printf("\nEnter a value: ");
      scanf("%d", &val);
      append(root, val);
      break;
    case 3:
      printf("\nEnter a value: ");
      scanf("%d", &val);
      printf("Enter the position: ");
      scanf("%d", &pos);
      insert(root, pos, val);
      break;
    case 4:
      pop(root);
      break;
    case 5:
      printf("\nEnter a value to delete: ");
      scanf("%d", &val);
      delete (root, val);
      break;
    case 6:
      printf("\nEnter a value to search: ");
      scanf("%d", &val);
      search(root, val);
      break;
    case 7:
      display(root);
      break;
    case 0:
      printf("\nPress any key exit...");
      getch();
      return (0);
      break;
    default:
      printf("\nInvalid input.");
      break;
    }
  }
}