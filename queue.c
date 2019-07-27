#include<stdio.h>
#define MAX 20

int opt, a[20], i, first, last, n;

void create(){
	printf("\n Enter the limit of the queue: ");
	scanf("%d", &n);
	first = 0, last = n - 1;
	if (n < MAX){
		printf("\n Enter the elements:\n");
		for (i = 0; i < n; i++){
			scanf("%d", & a[i]);
			last = n - 1;
		}
	}
	else
		printf(" Memory error!");
}

void enq(){
	int x;
	if (last < MAX){
		printf(" Enter the element to push: ");
		scanf("%d", &x);
		last += 1;
		a[last] = x;
		n = last;
	}
	else
		printf(" Queue limit is reached.");
}

void deq(){
	if(first > last)
		printf(" Error the queue is empty.");
	else{
		printf(" %d has left the queue.", a[first]);
		first += 1;
    }
}

void disp(){
	printf(" The elements are: ");
	for(i = first; i <= last; i++){
		printf("%d", a[i]);
		if (i != last)
			printf(", ");
		else
			printf(".");
	}
}


int main(){
	while(1){
		// clrscr();
		printf("\n === MENU ===");
		printf("\n 1. Create New \n 2. Enroll \n 3. Leave \n 4. Display \n 0. Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &opt);
		switch(opt){
			case 1: create(); disp(); break;
			case 2: enq(); break;
			case 3: deq(); break;
			case 4: disp(); break;
			case 0: return (0);
			default: printf("\n Invalid input!");
		}
	}
}
