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

    int i,j,min;
    for(int i=1;i<n;i++)
    {
        min=a[i];
        j=i-1;
        while(j>=0 && a[j]>min)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=min;
    }
       
    printf("\nThe Sorted Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}