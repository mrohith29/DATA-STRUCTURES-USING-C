#include<stdio.h>



int main()
{
    int i,n,a[10];
    printf("Enter the number of elements to sort ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter a[%d] : ",i);
        scanf("%d",&a[i]);
    }

    quicksort(a, n);

    printf("Sorted List\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
        
}