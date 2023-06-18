#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    printf("%d",sizeof(head));
}
