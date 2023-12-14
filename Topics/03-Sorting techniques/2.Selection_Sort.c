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

    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        int tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
    }
       
    printf("\nThe Sorted Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}