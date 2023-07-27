#include<stdio.h>
#include<stdlib.h>

#define queue_size 3
int cqueue[queue_size];
int front = -1, rear = -1;

void enqueue(int value)
{
    if((rear == queue_size-1 && front == -1)||(rear == front && front != -1))
    {
        printf("circular queue is full\n");
    }
    else
    {
        if(rear == queue_size-1 && front != -1)
        {
            rear = 0;
            cqueue[rear] = value;
        }
        else
        {
            rear++;
            cqueue[rear] = value;
        }
    }
}


void dequeue()
{
    if(front == rear && front == -1)
    {
        printf("circular queue is empty\n");
    }
    else
    {
        if(front == queue_size-1)
        {
            front = -1;
        }
        front++;
        printf("%d is deleted\n",cqueue[front]);
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
        printf("circular queue is empty\n");
    }
    else
    {
        if(front > rear)
        {
            for(int i=0;i<queue_size-1;i++)
            {
                printf("%d->",cqueue[i]);
            }
            for(int i=0;i<=rear;i++)
            {
                printf("%d",cqueue[i]);
            }
        }
        else
        {
            for(int i=front+1;i<=rear;i++)
            {
                printf("%d->",cqueue[i]);
            }
        }
    }
}

int main()
{
    int option,n;
    while (1)
    {
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            scanf("%d",&n);
                enqueue(n);
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
                break;
        }
    }
    
}