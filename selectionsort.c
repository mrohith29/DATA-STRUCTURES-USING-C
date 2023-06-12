#include<stdio.h>
int main()
{
    int i,n,min,temp,a[20];
    printf("Enter the number of elements to ne sorted\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }

        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;       
        }
    }
    printf("sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}