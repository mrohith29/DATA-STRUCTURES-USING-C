#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *ptr;
    scanf("%d",&ptr);
    printf("%d",sizeof(ptr));
}
