#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct linked_list *next;
} linked_list;

int main()
{
    linked_list *head = NULL;
    linked_list *one = NULL;
    linked_list *two = NULL;
    linked_list *three = NULL;

    one = (linked_list *)malloc(sizeof(linked_list));
    two = (linked_list *)malloc(sizeof(linked_list));
    three = (linked_list *)malloc(sizeof(linked_list));

    one->data = 3;
    two->data = 5;
    three->data = 7;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    int choice;
    printf("press 0 for insertion and 1 for deletion");
    scanf("%d", &choice);

    if (choice == 0)
    { // insertion
        int pos;
        printf("enter the position where you want to insert a node");
        scanf("%d", &pos);
        while (head != NULL)
        {
            for (int i = 1; i < pos - 1; i++)
            {
                head = head->next;
            }
        }
        linked_list *new_node = NULL;
        new_node = (linked_list *)malloc(sizeof(linked_list));
        new_node->data = 1;
        new_node->next = head->next;
        head->next = new_node;
        three->next = new_node;
    }
    else if (choice == 1)
    { // deletion
        int pos;
        printf("enter the position where you want to delete a node");
        scanf("%d", &pos);
        while (head != NULL)
        {
            for (int i = 1; i < pos; i++)
            {
                head = head->next;
            }
        }

        
    
    }
}