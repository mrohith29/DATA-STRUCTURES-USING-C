#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#define queue_size 3
struct pqueue
{
    char job;
    int pr;
}e[queue_size];

int front=-1,rear=-1;

void enqueue(char element, int p)
{
    if(rear==queue_size)
    {
        printf("queue is full\n");
    }
    else
    {
        rear++;
        e[rear].job=element;
        e[rear].pr=p;
    }
}


void dequeue()
{
    if(front==rear)
    {
        printf("\nqueue is empty");
    }
    else{
        front++;
        // printf("")
    }
}


void sort()
{
    int i,j;
    struct pqueue temp;
    for(i=front+1;i<=rear;i++)
    {
        for(j=i+1;j<=rear;j++)
        {
            if(e[i].pr<e[j].pr)
            {
                temp=e[i];
                e[i]=e[j];
                e[j]=temp;
            }
        }
    }
}


void display()
{
    int i;
    if(front==rear)
    {
        printf("\nqueue is empty\n");
    }
    else{
        printf("  job name\tpriority\n");
        for(i=front+1;i<=rear;i++)
        {
            printf("  %c\t-\t%d",e[i].job,e[i].pr);
        }
    }
}



void main()
{
    int p,ch;
    char element;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            scanf("%c %d",&element,&p);
            enqueue(element,p);
            sort();
            break;
            
            case 2:
            dequeue();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            exit(0);
        }
    }
}