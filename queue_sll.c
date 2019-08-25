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

void enqueue(list *list1){
  list *tmp = list1;
  for (; tmp->next != NULL; tmp = tmp->next);
  tmp -> next = createNode();
  printf("Element added the queue.");
}

list* newList() {
  int n;
  list *newList = (list*)malloc(sizeof(list));
  printf("\nHow many elements do you want to add? ");
  scanf("%d", &n);
  newList = createNode();
  printf("Element added succesfully.");
  for (int i = 0; i < n-1; i++)
    enqueue(newList);
  printf("\n\nList created succesfully.");
  return newList;
}
<<<<<<< HEAD

=======
/*
void dequeue(list *list1){
  list *tmp = list1;
  list1 = list1->next;
  tmp -> next = NULL;
  free(tmp);
  printf("%d have left the queue.", list1->data);
}
*/
>>>>>>> 95ae851cea4dc6dae5f1a24ea2268b5f58cbb677
void dequeue(list *list1){
  if (list1 == NULL){
    printf("\nThe queue is empty.");
    return;
  }
  list *tmp = list1;
  list1 = list1->next;
  printf("%d have left the queue.", tmp->data);
  free(tmp);
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
    printf("\n2. Enqueue");
    printf("\n3. Dequeue");
    printf("\n4. Display");
    printf("\n0. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("\nCreate new Queue...");
        list *list1 = newList();
        break;
      case 2:
        enqueue(list1);
        break;
      case 3:
        dequeue(list1);
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
