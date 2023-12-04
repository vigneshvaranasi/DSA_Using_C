#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void Quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        Quicksort(a, low, j - 1);
        Quicksort(a, j + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter Number of array Elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter Array Elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("The Array Elements Before Sorting are:");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int low = 0;
    int high = n - 1;

    Quicksort(a, low, high);

    printf("\nThe Sorted Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
