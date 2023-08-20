#include<stdio.h>
#include<stdlib.h>
#define size 5
int a[size];

void insert()
{
    int value;
    scanf("%d",&value);
    int k = value%size;
    if(a[k] == -1)
    {
        a[k] = value;
    }
    else
    {
        printf("Collision occered - cannot insert element\n");
    }
}

void delete()
{
    int value;
    scanf("%d",&value);
    int k = value%size;
    if(a[k] != -1)
    {
        printf("%d is deleted\n",a[k]);
        a[k] = -1;
    }
    else
    {
        printf("%d doesnot exist to delete\n",value);
    }
}

void display()
{
    int value;
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
}

void search()
{
    int value;
    scanf("%d",&value);
    int k = value%size;
    if(a[k] != -1)
    {
        printf("%d is found\n",value);
    }
    else
    {
        printf("%d element doesnot exists",value);
    }
}

int main()
{
    int option;
    for(int i =0 ;i< size;i++)
    a[i] = -1;
    while(1)
    {
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            search();
            break;

            case 5:
            exit(0);

            default:
            printf("enter a valid input\n");
        }
    }
}