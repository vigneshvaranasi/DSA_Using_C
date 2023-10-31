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
        int key;
        printf("Enter Element to Search:");
        scanf("%d",&key);
        int low=0;
        int high=n;
        int mid;
        while(low<high)
        {
                mid=(low+high)/2;
                if(key>a[mid])
                    low=mid+1;
                else
                    high=mid;
        }
        if(a[low]==key)
            printf("Element found at index:%d.",low);
        else 
            printf("Element Not Found.");

}