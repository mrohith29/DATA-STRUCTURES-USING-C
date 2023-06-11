#include<stdio.h>
int main()
{
    int i,n,a[20];
    printf("Enter the number of numbers to be entered\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        int temp,j;
        temp=a[i];
        j=i;
        while ((j>0) && (a[j-1]>temp))
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;    
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d  ",a[i]);
    }
    
}