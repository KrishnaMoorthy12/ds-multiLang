#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int hashVal(int value, int size) {
  int key = value % size;
  return key;
}

void hashTable(int hashed[]) {
  printf("\n ------------- ");
  printf("\n| Index  Value|");
  for (int i = 0; i < 10; i++){
    if (hashed[i] == 0)
      continue;
    else
      printf("\n| %d \t    %d|", i, hashed[i]);
  }
  printf("\n -------------- ");
}

int main() {
  int array[5] = {86, 67, 98, 17, 27};
  int hashed[10] = {0};
  int key;
  for (int i = 0; i < 5; i++) {
    key = hashVal(array[i], 10);
    if(hashed[key] == 0)
      hashed[key] = array[i];
    else {
      for(int j = key; j<10; j++) {
        if (hashed[j] == 0){
          hashed[j] = array[i];
          break;
        }
        if (j == 9)
          j = -1;
      }
    }
  }
  hashTable(hashed);
}