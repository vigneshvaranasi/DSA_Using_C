#include <stdio.h>
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

    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }

    printf("\nThe Sorted Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}