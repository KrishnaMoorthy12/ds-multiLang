#include <stdio.h>
#define MAX 20
int opt, a[20], i, top = 0, n;
void create(){
	printf("\n Enter the length of the stack: ");
	scanf("%d", &n);
	printf("\n Enter the elements:\n");
	if (n < MAX){
		for (i = 0; i < n; i++){
			scanf("%d", & a[i]);
		}
		top = n - 1;
		n -= 1;
	}
	else
		printf(" Memory error");
}

void display(){
	if (top < 0){
		printf(" The stack is empty");
	}
	else{
		printf(" The elements are: ");
		for (i = top; i >= 0; i--){
			printf("%d", a[i]);
			if (i != 0)
				printf(", ");
			else
				printf(".");
		}
	}
}

void push(){
	int x;
	if (top < MAX){
		printf(" Enter the element to push:");
		scanf("%d", &x);
		top += 1;
		a[top] = x;
		n = top;
	}
	else
		printf(" Stack is full, memory limit reached.");
}

void pop(){
	if (!(n >= 0))
		printf(" The stack is empty");
	else{
		printf(" Popped element is: %d", a[n]);
		n -= 1;
		top = n;
	}
}

int main(){
	while(1){
		// clrscr();
		printf("\n === MENU ===");
		printf("\n 1. Create New \n 2. Push \n 3. Pop \n 4. Display \n 0. Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &opt);
		switch(opt){
			case 1: create(); display(); break;
			case 2: push(); break;
			case 3: pop(); break;
			case 4: display(); break;
			case 0: return (0);
			default: printf("\n Invalid input!");
		}
	}
}
