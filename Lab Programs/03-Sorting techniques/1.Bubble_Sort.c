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

    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
            }
        }
    }
    printf("\nThe Sorted Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}