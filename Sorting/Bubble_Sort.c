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

        printf("\nSorted Array is:");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);

}