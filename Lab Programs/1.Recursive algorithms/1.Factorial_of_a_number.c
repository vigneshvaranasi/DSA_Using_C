#include<stdio.h>
int fact(int n)
{
    int ans;
    if(n==1 || n==0)
        ans=1;
    else
        ans=n*fact(n-1);
    return ans;
}
int main()
{
    int n;
    printf("Enter a Number to get its Factorial:");
    scanf("%d",&n);
    printf("Factorial of given number is:%d\n",fact(n));
}