#include<stdio.h>
int main()
{
    int i,j,temp,n,a[20];
    printf("Enter the number of elements needed to be sorted\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i;j>0,a[j-1]>temp;j++)
        {
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}
