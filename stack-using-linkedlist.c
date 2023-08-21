#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
}*top = NULL;

void push()
{
    int element;
    scanf("%d",&element);
    struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->data = element;
    newnode->next = NULL;
    if(top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}


void pop()
{
    if(top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("%d is deleted from the stack\n",top->data);
        top = top->next;
    }
}

void display()
{
    struct stack *temp;
    temp = top;
    if(temp == NULL)
    {
        printf("stack is empty - nothing to display\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        
    }
}

int main()
{
    int option;
    while(1)
    {
        printf("\n1) push\n2) pop\n3) display\n4)exit\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        
        default:
            printf("please enter a valid option\n");
            break;
        }
    }
}
