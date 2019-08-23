#include "stdio.h"
#include "stdlib.h"
struct list {
  int data;
  struct list *prev, *next;
}*head=NULL;

void create(int);
void IAM(int,int);
void display();
void DAM(int);

void main()
{
  int n;
  "cls";
  // scanf("%d\n",&n);
  create(10);
  create(20);
  create(30);
  IAM(20,25);
  DAM(20);
  display();
  getch();
}

void create(int num)
{
  struct list *t,*n;
  if(head==NULL)
  {
    head=malloc(sizeof(struct list));
    head->data=num;
    head->prev=head;
    head->next=head;
  }
  else
  {
    t=head;
    while (t->next!=head) {
      t=t->next;
    }
    n=malloc(sizeof(struct list));
    n->data=num;
    t->next=n;
    n->next=head;
    n->prev=t;
  }
}

void IAM(int key,int num)
{
  struct list *t,*n;
  t=head;
  while(t->data!=key)
  {
    if(t->next==head)
      break;
    t=t->next;
  }
  n=malloc(sizeof(struct list));
  n->data=num;
  n->next=t->next;
  t->next=n;
  n->prev=t;
  n->next->prev=n;
}

void display()
{
  struct list *t;
  t=head;
  printf("\n");
  do
  {
    printf("%d   ",t->data);
    t=t->next;
  }while(t!=head);
}

void DAM(int num)
{
  struct list *t;
  t=head;
  while(t->data!=num){
    if(t->next==head)break;
    t=t->next;
  }
  if(t->data==num){
  t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
  }
  else{printf("\nElemnt not found!");}
}
