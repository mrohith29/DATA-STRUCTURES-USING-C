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

void insert_at_beginning(struct node *head,int data)
{
    printf("Enter the data to enter before at the beginning");
    scanf(" %d ", &head->data);
    head->next = head;

}
int main()
{
    int option;
    struct node *head;
    // struct node *newnode;
    
    // newnode=(struct node*)malloc(sizeof(struct node));
    head= (struct node*)malloc(sizeof(struct node));
    printf("Enter the element in the new node.\n");
    scanf("%d", &head->data);
    head->next = NULL;  

    // if(head==NULL)
    // {
    //    / head = newnode;
        
    // }
    printf("%d\n",head->data);
    // printf("%d\n",&head->data);
    printf("Select your option:\n\
    1. Insert at the beginning of the element\n\
    2. Insert before the element\n\
    3. Insert after the element\n");

    // scanf("%d",option);
    // switch(option)
    // {
    //     case 1: insert_at_beginning(head);
    //     break;
    // }

}
