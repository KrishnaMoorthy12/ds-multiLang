#include "stdio.h"
#include "stdlib.h"

struct node {
  int data;
  struct node *next;
};

typedef struct node list;

void create(list *list1) {
  int n;
  // list start = list1;
  printf("\n%s", "Enter the number of elements: ");
  scanf("%d", &n);
  printf("\nEnter the elements:\n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &list1->data);
    list1 = list1->next;
  }
  printf("List was created succesfully.");
}

void insert(list *list1){
  printf("Enter the element: ");
  scanf("%d", &list1->data);
  printf("\nElement added succesfully.");
}

void pop(list *list1){
  for(;list1->next!=NULL; list1=list1->next){
    if ((list1->next)->next == NULL){
      printf("Popped element: ", list1->data);
      list1->next = NULL;
    }
  }
}

void display(list *list1){
  list *temp = list1;
  printf("\nThe elements are: ");
  while(temp!=NULL){
    printf("%d", list1->data);
    if (list1->next != NULL)
      printf(", ");
    else
      printf(".");
    temp=temp->next;
  }
}

int main(int argc, char const *argv[]) {
  int ch;
  static int a = -1;
  list *list1[5];
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
        printf("\n> Create new Singly Linked List...");
        a++;
        list1[a] = (list*)malloc(sizeof(list));
        create(list1[a]);
        break;
      case 2:
        printf("\n> Insert a new node...");
        insert(list1[a]);
        break;
      case 3:
        pop(list1[a]);
        break;
      case 4:
        display(list1[a]);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid input.");
    }
  }
  return 0;
}
