#include<stdio.h>
int main()
{
    int a[10],i,n;
    printf("enter the number of elements you want to sort ");
    scanf("%d",&n);
    printf("enter the element\n");
    for ( i = 0; i < n; i++)
    {
        printf("enter element a[%d]",i);
        scanf("%d",a[i]);
    }
    
    mergesort(a,n);
}