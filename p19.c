#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};

int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;
  
  int num=2;  //it is the value we want to search 
  int i=1;
  head=one;

  while(head->next!=NULL){
    if (head->value==num)
    printf("the given element is found at node %d\n",i);

    i++;
    head=head->next;
  }
head=one;
   while(head!=NULL){
    printf("%d\n",head->value);
    head=head->next;
   }
}