#include <stdio.h>
#include <stdlib.h>

int fib(n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    return 1 + fib(n-1)+fib(n-2);    
    
}

int main()
{
    return 0;
}