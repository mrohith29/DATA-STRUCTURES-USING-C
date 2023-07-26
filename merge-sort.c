#include <stdio.h>

void quicksort(int a[], int low, int high);

int main()
{
    int i, n, a[10];
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("Sorted List:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void quicksort(int a[], int low, int high)
{
    int i, temp;
    if (low < high)
    {
        int l = low;
        int h = high;
        int pivot = a[l];

        while (low < high)
        {
            while (a[l] <= pivot && l < high)
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
        a[low] = pivot;
        quicksort(a, low, h - 1);
        quicksort(a, h + 1, high);
    }
}
