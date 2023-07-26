#include<stdio.h>

void radixsort(int a[], int n)
{
    int bkt[10][10], bktcount[10];
    int i,j,k,nod = 0,rem,pass,di = 1,big = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>big)
        {
            big = a[i];
        }
    }
    while(big != 0)
    {
        nod++;
        big = big/10;
    }
    for(pass=1;pass<=nod;pass++)
    {
        for(i=0;i<10;i++)
        {
            bktcount[i] = 0;
        }
        for(i=0;i<n;i++)
        {
            rem = (a[i]/di)%10;
            bkt[rem][bktcount[rem]] = a[i];
            bktcount[rem]+=1;
        }
        i = 0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bktcount[k];j++)
            {
                a[i]=bkt[k][j];
                i++;
            }
        }
        di = di*10;
    }
}

int main()
{
    int a[10],n,i;
    printf("enter the number of elements to sort : ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    radixsort(a, n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}