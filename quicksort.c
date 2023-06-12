#include <stdio.h>
int printarray(int a[], int n)
{
    printf("Unsorted List\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    int temp;
    do
    {
        while (i < j)
        {
            while (a[i] <= pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
int quicksort(int a[], int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition(a, low, high);
        quicksort(a, low, partition_index - 1);
        quicksort(a, partition_index + 1, high);
    }
}

int print(int a[], int low, int high)
{
    printf("\nQUICK SORT\n");
    printf("Sorted List\n");
    int i;
    for (i = 0; i < high; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[20], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printarray(a, n);
    quicksort(a, 0, n - 1);
    print(a, 0, n);
}