#include "stdio.h"
#include "stdlib.h"

struct node{
  int data;
  struct node *next;
};

typedef struct node list;

list* createNode() {
  list *newNode = (list*)malloc(sizeof(list));
  printf("\nEnter the value: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  return newNode;
}

void append(list *list1){
  list *tmp = list1;
  for (; tmp->next != NULL; tmp = tmp->next);
  tmp -> next = createNode();
  printf("Element added succesfully.");
}

list* newList() {
  int n;
  list *newList = (list*)malloc(sizeof(list));
  printf("\nHow many elements do you want to add?");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    append(newList);
  }
  printf("\n\nList created succesfully.");
  return newList;
}

void pop(list *list1){
  list *tmp = list1;
  for(;tmp->next->next != NULL; tmp = tmp->next);
  printf("Popped element: %d", tmp->next->data);
  free(tmp->next);
  tmp->next = NULL;
}

void display(list *list1){
  list *temp = list1;
  printf("\nThe elements are: ");
  while(temp!=NULL){
    printf("%d", temp->data);
    if (temp->next != NULL)
      printf(", ");
    else
      printf(".");
    temp=temp->next;
  }
}

int main(int argc, char const *argv[]) {

  list *list1;
  list1 = (list*)malloc(sizeof(list));
  int ch;
  while (1) {
    printf("\n==== MENU ====");
    printf("\n1. Create");
    printf("\n2. Insert");
    printf("\n3. Pop");
    printf("\n4. Display");
    printf("\n0. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("\nCreate new Singly Linked List...");
        list *list1 = newList();
        break;
      case 2:
        printf("\nInsert a new node...");
        append(list1);
        break;
      case 3:
        pop(list1);
        break;
      case 4:
        display(list1);
        break;
      case 5:
      case 0:
        return 0;
      default:
        printf("Invalid input.");
    }
  }
  return 0;
}
