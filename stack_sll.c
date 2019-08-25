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

void add(list *list1){
  list *tmp = list1;
  for (; tmp->next != NULL; tmp = tmp->next);
  tmp -> next = createNode();
  printf("%d was added to the stack.", tmp->next->data);
}

list* newList() {
  int n;
  list *newList = (list*)malloc(sizeof(list));
  printf("\nHow many elements do you want to add? ");
  scanf("%d", &n);
  newList = createNode();
  printf("Element added succesfully.");
  for (int i = 0; i < n-1; i++) {
    add(newList);
  }
  printf("\n\nList created succesfully.");
  return newList;
}

void take(list *list1){
  list *tmp = list1;
  for(;tmp->next->next != NULL; tmp = tmp->next);
  printf("%d was taken out from the stack.", tmp->next->data);
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
    printf("\n\n==== MENU ====");
    printf("\n1. Create");
    printf("\n2. Add");
    printf("\n3. Take");
    printf("\n4. Display");
    printf("\n0. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("\nCreate new Stack...");
        list *list1 = newList();
        break;
      case 2:
        add(list1);
        break;
      case 3:
        take(list1);
        break;
      case 4:
        display(list1);
        break;
      case 5:
      case 0:
        printf("\nExiting...\n");
        return 0;
      default:
        printf("Invalid input.");
    }
  }
  return 0;
}
