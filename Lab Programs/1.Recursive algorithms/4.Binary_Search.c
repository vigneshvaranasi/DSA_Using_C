#include<stdio.h>
int binarysearch(int a[],int low,int high,int key)
{
    if(low==high)
    {
        if(a[low]==key)
            return low;
        else
            return -1;
    }
    else
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            return binarysearch(a,low,mid-1,key);
        else
            return binarysearch(a,mid+1,high,key);
    }
}

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
    int res=binarysearch(a,low,high,key);
    if(res!=-1)
    {
        printf("Element Found at index:%d",res);
    }
    else
    {
        printf("Element Not Found");
    }
}