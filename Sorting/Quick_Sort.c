#include<stdio.h>
void main()
{
        int n;
        printf("Enter Number of Elements:");
        scanf("%d",&n);
        int a[n];
        printf("Enter Elements:");
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Given Elements are:");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);

        int temp,min;
                       



        printf("\nSorted Array is:");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);

}