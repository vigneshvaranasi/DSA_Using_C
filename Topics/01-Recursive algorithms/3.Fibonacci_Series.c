#include<stdio.h>
int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    printf("Enter The Number of elements in series:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",fib(i));
    }
    printf("\n");
}