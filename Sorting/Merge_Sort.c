#include <stdio.h>

void Merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[ub + 1];

    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Given Elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    MergeSort(a, 0, n - 1);

    printf("\nSorted Array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
