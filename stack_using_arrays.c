#include <stdio.h>
#include <stdlib.h>

#define stack_size 5

int stack[stack_size];
int top = -1;

int push(int element)
{
    if (top == stack_size - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        stack[++top] = element;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack is empty\t nothing to delete");
    }
    else
    {
        int delement;
        delement = stack[top];
        printf("deleted %d\n", delement);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("stack is empty, therefore no top element\n");
    }
    else
    {
        printf("%d\n",stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d->", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, option;
    while (1)
    {
        printf("1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            scanf("%d", &n);
            push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;
            
        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            break;
        }
    }
}