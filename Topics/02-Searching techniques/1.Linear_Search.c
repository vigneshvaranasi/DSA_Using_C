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
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("\nElement Found at Position:%d",i);
            return 0;
        }       
    }
    printf("\nElement Not Found");
}