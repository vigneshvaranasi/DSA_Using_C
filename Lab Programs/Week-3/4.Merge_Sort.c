#include <stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int b[high+1];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(k=low;k<=high;k++)
        a[k]=b[k];
}
void Mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        Mergesort(a,low,mid);
        Mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

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

    int low=0;
    int high=n-1;

    Mergesort(a,low,high);
       
    printf("\nThe Sorted Array is : ");
    for (int i = 0; i <n; i++)
        printf("%d ", a[i]);
}