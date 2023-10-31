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

        for(int i=0;i<n-1;i++)
        {
                min=i;
                for(int j=i+1;j<n;j++)
                {
                        if(a[min]>a[j])
                            min=j;
                }
                temp=a[min];
                a[min]=a[i];
                a[i]=temp;
        }

        printf("\nSorted Array is:");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);

}