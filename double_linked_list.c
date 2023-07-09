#include<stdio.h>
#include<stdlib.h>
struct dll
{
    struct dll *prev;
    int data;
    struct dll *next;
}*head;

int nodes()
{
    int c = 1;
    struct dll *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

int count = 0;

struct dll *insert_node()
{
    int key,position,data;
    struct dll *ptr,*newnode;
    newnode = (struct dll*)malloc(sizeof(struct dll));
    scanf("%d %d",&newnode->data,&position);
    newnode->prev = NULL;
    newnode->next = NULL;



    int p = nodes();
    int c = 1;
    if(position > p)
    {
        printf("Enter a valid position\n");
    }
    else
    {
        if(head == NULL)
        {
            head = newnode;
        }
        else if(position == 1)
        {
            ptr = head;
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else if(position == p)
        {
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
                ptr->next = newnode;
                newnode->prev = ptr;
        }
        else
        {
            ptr = head;
            while(position != c)
            {
                ptr = ptr->next;
                c++;
            }
            newnode->next = ptr;
            newnode->prev = ptr->prev;
            ptr->prev->next = newnode;
            ptr->prev = newnode;
        }
    }
}


struct dll *delete_node()
{
    int count = 1, n = nodes();
    int key;
    struct dll *ptr,*temp;
    ptr = head;
    scanf("%d",&key);
    if(key >= n)
    {
        printf("Enter a valid position\n");
    }
    else
    {
        if(head == NULL)
        {
            printf("DLL is empty\n");
        }
        else if(key == 1)
        {
            if(head->next == NULL)
            {
                free(head);
                head = NULL;
            }
            else{
                ptr = head;
                head->next->prev = NULL;
                head = head->next;
                free(ptr);
            }
        }
        else if(key == n-1)
        {
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            free(ptr);
        }
        else
        {
            ptr = head;
            while( count != key)
            {
                temp = ptr;
                ptr = ptr->next;
                count++;
            }
            temp->next = ptr->next;
            ptr->next->prev = temp;
            free(ptr);
        }
    }
}


struct dll *display_dll()
{
    struct dll *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("DLL is empty\n");
    }
    else
    {
        printf("FORWARD Traversal: ");
        while(ptr->next != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
        printf("\n");
        printf("BACKWARD Traversal: ");
        printf("%d ",ptr->data);
        ptr = ptr->prev;
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->prev;
        }
        printf("\n");
    }
    
}


struct dll *search_node()
{
    int key, count = 0;
    struct dll *ptr;
    scanf("%d",&key);
    ptr = head;
    if(head == NULL)
    {
        printf("DLL is empty\n");
    }
    else
    {
        while((ptr->data != key) && (ptr->next != NULL))
        {
            count++;
            ptr = ptr->next;
        }
        if(ptr->data == key)
        {
            printf("%d found at position %d\n",key,count+1);
        }
        else
        {
            printf("element not found\n");
        }
    }
}



int main()
{
    int option;
    while(1)
    {
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            insert_node();
            break;
            
            case 2:
            delete_node();
            break;
            
            case 3:
            display_dll();
            break;
            
            case 4:
            search_node();
            break;
            
            case 5:
            exit(0);
            
            default:
            printf("invalid choice");
        }
    }
}