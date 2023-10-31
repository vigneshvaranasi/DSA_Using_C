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
        int key,pos=-1;
        printf("Enter Element to search:");
        scanf("%d",&key);
        for(int i=0;i<n;i++)
        {
                if(a[i]==key)
                    pos=i;
        }
        if(pos==-1)
            printf("Element Not Found.");
        else
            printf("Element Found at index:%d.",pos);
}