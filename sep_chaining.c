#include "stdio.h"
#include "stdlib.h"

struct chain {
  int data;
  struct chain *next;
};


void displayNode(struct chain *node) {
  if (node == NULL){
    printf("NULL");
    return;
  }
  else {
    printf("%d", node->data);
    displayNode(node->next);
  }
}

void display(struct chain *root[]) {
  for (int i = 0; i<10; i++) {
    displayNode(root[i]);
  }
}

struct chain* hash(int a[], int size) {
  struct chain *table[10] = {NULL};
  struct chain *tmp, *pr;
  int mod;
  for (int i = 0; i < size; i++) {
    mod = a[i] % 10;
    if(table[mod] == NULL) {
      tmp = table[mod];
      tmp = (struct chain *)malloc(sizeof(struct chain));
      tmp->data = a[i];
      tmp->next = NULL;
    }
    else if(table[mod] != NULL) {
      tmp = table[mod];
      while(tmp->next != NULL) {
        tmp = tmp->next;
      }
      if (tmp->next == NULL) {
        pr = (struct chain *)malloc(sizeof(struct chain));
        pr->data = a[i];
        pr->next = NULL;
        tmp->next = pr;
      }
      continue;
    }
  }
  return *table;
}

int main() {
  int a[] = {3, 18, 9, 10, 14};
  struct chain *table = hash(a, 5);
  display(table);
}