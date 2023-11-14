#include <stdio.h>
void main()
{
    int n;
    printf("Enter Number of Elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter Elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Given Elements are:");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
  
    int i, j, min;
    for (i = 1; i < n; i++)
    {
        min = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > min)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = min;
    }

    printf("\nSorted Array is:");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
}