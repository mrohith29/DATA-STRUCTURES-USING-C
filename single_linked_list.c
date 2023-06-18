#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct node* insert_at_beginning(struct node *head)
{
    // int info;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to enter before at the beginning");
    
    scanf(" %d ", &ptr->data);
    ptr->next = head;
    return head;
}
int main()
{
    int option;
    struct node *head;
    
    head= (struct node*)malloc(sizeof(struct node));
    printf("Enter the element in the \"head\".\n");
    scanf("%d", &head->data);
    head->next = NULL;  

    // printf("%d\n",head->data);
    
    printf("Select your option:\n\
    1. Insert at the beginning of the element\n\
    2. Insert before the element\n\
    3. Insert after the element\n");
    while(1)
    {
    scanf("%d",option);
    switch(option)
    {
        case 1:
         insert_at_beginning(head);
        break;
         case 2:
         linkedlisttraversal(head);
        break;
    }
    }
}
