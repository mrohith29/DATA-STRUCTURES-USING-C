#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insert_at_beginning(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to enter before at the beginning\n");
    scanf("%d", &ptr->data);
    ptr->next = head;
    return ptr;
    // while(ptr!=NULL)
    // {
    //     printf("%d\n",ptr->data);
    //     ptr=ptr->next;
    // }
}

struct node *insert_at_end(struct node *head)
{
    int data;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element needed to insert at the end\n");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = NULL;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return p;
}

struct node *insert_after_element(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int data, reference;
    printf("Enter the element before which you want to insert the element.\n");
    scanf("%d", &reference);
    printf("Enter the data to insert.\n");
    scanf("%d", &data);
    ptr->data = data;
    struct node *p;
    while (p->data != reference)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return p;
}

// struct node *insert_before_element(struct node *head)
// {
//     int element,data;
//     struct node *ptr = (struct node*)malloc(sizeof(struct node));
//     printf("Enter the element before which you want to enter the data\n");
//     scanf("%d",&element);
//     int k=0;
//     struct node *p = (struct node*)malloc(sizeof(struct node));
//     p = head;
//     while(p->next != element)
//     {
//         p = p->next;
//         k++;
//     }
//     p = head;
//     while(k != 1 && )
//     {
//         p
//     }
// }
struct node *Delete_at_beginning(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *Delete_at_end(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *Delete_in_between(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    printf("Enter the element which you want to Delete\n");
    int element;
    scanf("%d",&element);
    while(q->data != element)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;

}


int main()
{
    int option;
    struct node *head;

    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element in the \"head\".\n");
    scanf("%d", &head->data);
    head->next = NULL;

    // printf("%d\n",head->data);

    while (1)
    {

        printf("Select your option:\n\
    -1. Display the list\n\
    1. Insert at the beginning of the element\n\
    2. Insert before the element\n\
    3. Insert after the element\n\
    4. Insert at the end\n\
    5. Delete at bigenning\n\
    6. Delete at end\n\
    7. Delete in middle\n\
    0. exit\n");


        scanf("%d", &option);
        switch (option)
        {
        case 0:
            exit(0);
        case 1:
            head = insert_at_beginning(head);
            break;
        case -1:
            linkedlisttraversal(head);
            break;
        case 4:
            head = insert_at_end(head);
            break;
        case 3:
            head = insert_after_element(head);
            break;
        case 5:
            head = Delete_at_beginning(head);
            break;
        case 6:
            head = Delete_at_end(head);
            break;
        case 7:
            head = Delete_in_between(head);
            break;
        }
    }
}
