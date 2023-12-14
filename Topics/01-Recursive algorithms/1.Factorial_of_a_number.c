#include<stdio.h>
int fact(int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter a Number to get its Factorial:");
    scanf("%d",&n);
    printf("Factorial of given number is:%d\n",fact(n));
}