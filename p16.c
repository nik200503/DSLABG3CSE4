#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct linked_list *next;
}linked_list;

int main(){
    linked_list *head=NULL;
    linked_list *one=NULL;
    linked_list *two=NULL;
    linked_list *three=NULL;

    one=(linked_list*)malloc(sizeof(linked_list));
    two=(linked_list*)malloc(sizeof(linked_list));
    three=(linked_list*)malloc(sizeof(linked_list));

    one->data=3;
    two->data=5;
    three->data=7;

    one->next=two;
    two->next=three;
    three->next=NULL;

    head=one;

    int choice;
    printf("press 0 for insertion and 1 for deletion at begining");
    scanf("%d",&choice);

    if(choice==0){ //insertion at he begining
        linked_list *new_node=NULL;
        new_node=(linked_list*)malloc(sizeof(linked_list));
        new_node->data=1;
        new_node->next=one;
        head=new_node;
    }
    else if(choice==1){//deletion a he begining
        head=two;
        free(one);
    }
}