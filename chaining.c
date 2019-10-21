#include "stdio.h"
#include "stdlib.h"

struct chain {
  int data;
  struct chain *next;
};

int hashVal(int value, int size) {
  int key = value % size;
  return key;
}

void hashTable(struct chain *hashed[]) {
  printf("\n ------------- ");
  printf("\n| Index  Value|");
  for (int i = 0; i < 10; i++){
    if (hashed[i] == NULL)
      continue;
    else {
      while(hashed[i] != NULL) {
        printf("\n| %d \t    %d|", i, hashed[i]->data);
        hashed[i] = hashed[i]->next;
      }
    }
  }
  printf("\n -------------- ");
}

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

int main() {
  int size = 10;
  struct chain *table[size];
  for (int i = 0; i < size; i++){
    table[i] = (struct chain*)malloc(sizeof(struct chain));
  }
  int array[5] = {86, 67, 87, 15, 24};
  for (int i = 0; i < 5; i++) {
    int key = hashVal(array[i], 10);
    if(table[key] == NULL) {
      table[key] = (struct chain *)malloc(sizeof(struct chain));
      table[key]->data = array[i];
      printf("\n%d", table[key]->data);
      continue;
    }
    else {
      printf("\n%d Trying to chain...", array[i]);
      while(table[key] == NULL) {
        printf("\nattempting...");
        table[key] = table[key]->next;
      }
      printf("\nAttempt success!\n");
      printf("\t True");
      table[key]->next = (struct chain*)malloc(sizeof(struct chain));
      table[key] = table[key]->next;
      table[key]->data = array[i];
      continue;
    }
  }
  printf("\n Hashed.");
  // hashTable(table);
  display(table);
}