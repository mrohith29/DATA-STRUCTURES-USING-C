#include <stdio.h>

void quicksort(int a[], int low, int high);

int main()
{
    int a[10], i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted List\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("\nQUICK SORT\nSorted List\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void quicksort(int a[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        int l = low;
        int h = high;
        pivot = a[l];
        while (l < h)
        {
            while (a[l] <= pivot && l < h)
            {
                l++;
            }
            while (a[h] > pivot)
            {
                h--;
            }
            if (l < h)
            {
                temp = a[h];
                a[h] = a[l];
                a[l] = temp;
            }
        }
        temp = a[h];
        a[h] = a[low];
        a[low] = temp;

        quicksort(a, low, h - 1);
        quicksort(a, h + 1, high);
    }
}
