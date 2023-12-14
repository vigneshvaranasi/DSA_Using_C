#include<stdio.h>
int main()
{
    int n;
    printf("Enter Number of Elememnt in an array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter Elements of The Array:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nThe Elements of Array are:");
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
    int key;
    printf("\nEnter Element to Search:");
    scanf("%d",&key);
    
    int low=0;
    int high=n-1;
    int mid;
    while(low<high)
    {
        mid=(low+high)/2;
        if(key>a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    if(a[low]==key)
    {
        printf("Element Found at index:%d",low);
    }
    else
    {
        printf("Element Not Found");
    }
}