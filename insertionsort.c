#include<stdio.h>
int main()
{
    int i,j,n,a[10],b[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Unsorted List\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\nINSERTION SORT\nSorted List\n");
    for(i=1;i<n;i++)
    {
        int temp=a[i];
        for(j=i;j>0,a[j-1]>temp;j--)
        {
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}