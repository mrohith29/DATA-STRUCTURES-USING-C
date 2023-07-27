#include<stdio.h>
#include<stdlib.h>

#define queue_size 5

int queue[queue_size];
int front = -1, rear = -1;


void enqueue()
{
    if(rear == queue_size-1)
    {
        printf("queue is full\n");
    }
    else
    {
        int value;
        rear++;
        scanf("%d",&value);
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == rear && front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        front += 1;
        printf("%d is deleted\n",queue[front]);
    }
        if(front == rear)
        {
            front = rear = -1;
        }
}

void display()
{
    if(front == rear && front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for(int i=front+1;i<=rear;i++)
        {
            printf("%d->",queue[i]);
        }
    }
}

int main()
{
    int n,option;
    while (1)
    {
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;
        
        case 3:
            display();
            break;

        case 4:
        exit(0);

        default:
        printf("invalid choice\n");
            break;
        }
    }
    
}