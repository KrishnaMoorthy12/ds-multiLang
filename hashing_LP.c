#include<stdio.h>
#include<conio.h>

typedef int Index;

Index
hashKey(int hashVal, int tableSize) {
  printf("%d",hashVal % tableSize);
  return (hashVal % tableSize);
}

void hash(int list[], int result[]) {
  int tableSize = sizeof(result)/ sizeof(int);
  for (int i = 0; i < sizeof(list) / sizeof(int); i++) {
    result[hashKey(list[i], tableSize)] = list[i];
  }
}

void hashTable(int list[]) {
  for (int i = 0; i<10; i++) {
    printf ("\n%d \t %d", i, list[i]);
  }
}

int main() {
  int array[5] = {6, 7, 18, 8, 28};
  int result[10];
  hash(array, result);
  hashTable(result);
}