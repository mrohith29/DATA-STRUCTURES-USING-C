#include<stdio.h>

int mergesort(int a[], int mid, int low, int high)
{
    int i,j,k,b[10];
    i = low;
    j = mid+1;
    k = low;
    while(i <= mid && j <= high)
    {
        if(a[i] > a[j])
        {
            b[k] = a[j];
            j++;
            k++;
        }
        else{
            b[k] = a[i];
            i++;
            k++;
        }
    }
        while(i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
        while (j <= high)
        {
            b[k] = a[j];
            j++;
            k++;
        }        
    
    for ( i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
        
}

int divide(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low + high)/2;
        divide(a, low, mid);
        divide(a, mid+1, high);
        mergesort(a, mid, low, high);
    }
}

int main()
{
    int a[10],i,n;
    printf("enter the number of elements you want to sort ");
    scanf("%d",&n);
    printf("enter the element\n");
    for ( i = 0; i < n; i++)
    {
        printf("enter element a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    divide(a, 0, n-1);
    printf("SORTED LIST\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }    
}