#include <stdio.h>
int main()
{
    int n, m, o;
    printf("Enter the size of first Array:");
    scanf("%d", &n);
    int a[n];
    printf("Enter First Array Elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the size of Second Array:");
    scanf("%d", &m);
    int b[m];
    printf("Enter Second Array Elements:");
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    o = n + m;
    int c[o];
    int i=0,j=0,k=0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("\nThe Merged Array is : ");
    for (int i = 0; i < o; i++)
        printf("%d ", c[i]);
}