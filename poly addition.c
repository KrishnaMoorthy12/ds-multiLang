#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct poly {
   int coeff;
   int power;
   struct poly *next;
};

struct poly* create();
void display(struct poly *list);
void addpoly();

struct poly *list1 = NULL, *list2 = NULL, *add = NULL;
int main() {
  list1 = create();
  list2 = create();
  printf("\nEquation 1\n");
  display(list1);
  printf("\nEquation 2\n");
  display(list2);
  addpoly();
  printf("\nAnswer \n");
  display(add);
}

struct poly* create() {
   int power,coeff,num,i;
   static int j = 1;
   struct poly *temp,*ptr, *list = NULL;
   printf("\nEquation %d", j);
   printf("\nEnter the number of terms:");
   scanf("%d", &num);
   for(i = 1; i <= num; i++) {
       temp=(struct poly*)malloc(sizeof(struct poly));
	   printf("Enter the power:");
	   scanf("%d", &power);
	   printf("Enter the coefficient:");
	   scanf("%d", &coeff);
	   temp->coeff = coeff;
	   temp->power = power;
	   temp->next = NULL;
	   if(list == NULL)
	       list = temp;
	   else {
	        ptr = list;
			while(ptr->next != NULL)
			    ptr = ptr->next;
		    ptr->next = temp;
	   }
   }
	printf("\nSuccessfully Created %d\n", j);
	j++;
   return list;
}

void display(struct poly *list) {
    struct poly *ptr;
	ptr=list;
	while(ptr != NULL) {
		printf(" %d x^%d ", ptr->coeff, ptr->power);
		ptr = ptr->next;
		if(ptr != NULL)
            printf("+");
    }

}

void addpoly() {
    struct poly *temp1,*temp2,*temp;
	temp1 = list1;
	temp2 = list2;
    temp = (struct poly*)malloc(sizeof(struct poly));
    add = temp;
    temp->next = NULL;
    while((temp1 != NULL) || (temp2 != NULL)) {
       if(temp1 == NULL) {
           temp->coeff = temp2->coeff;
	       temp->power = temp2->power;
	       temp2 = temp2->next;
		   goto createnode;
        }
        if(temp2 == NULL){
           temp->coeff = temp1->coeff;
	       temp->power = temp1->power;
	       temp1 = temp1->next;
		   goto createnode;
        }
      if(temp1->power == temp2->power) {
	      temp->coeff = temp1->coeff + temp2->coeff ;
	      temp->power = temp1->power;
	      temp1 = temp1->next;
		    temp2 = temp2->next;
	    }
	    else if((temp1->power) > (temp2->power)) {
        temp->coeff = temp1->coeff;
	      temp->power = temp1->power;
		    temp1 = temp1->next;
	    }
	    else {
	      temp->coeff = temp2->coeff;
	      temp->power = temp2->power;
	      temp2 = temp2->next;
	    }

	   createnode:
	   if((temp1 != NULL) || (temp2 != NULL)){
           temp->next=(struct poly*)malloc(sizeof(struct poly));
           temp=temp->next;
           temp->next=NULL;
       }

	}
}
