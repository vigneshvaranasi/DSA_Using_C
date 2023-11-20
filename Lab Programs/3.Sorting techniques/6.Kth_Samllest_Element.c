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

    /* Start Sort */
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
    
    int k;
    printf("Enter vvalue to find kth samllest element:");
    scanf("%d",&k);
    printf("The kth Smallest element is:");
    printf("%d ", a[k-1]);
}