#include<stdio.h>

void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb,k=lb,j=mid+1;
    int b[20];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }

        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
        b[k]=arr[j];
        j++;
        k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<ub;k++)
    {
        arr[k]=b[k];
    }
}


void mergesort(int arr[],int lb,int ub)
{

    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}



int main()
{
    int arr[]={33,21,23,78,54,45,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("The array Before sorted");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    } 
    int lb=0,ub=n-1;
    mergesort(arr,lb,ub);
      printf("The array after sorted");
      printf("\n");
     for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    } 

}
