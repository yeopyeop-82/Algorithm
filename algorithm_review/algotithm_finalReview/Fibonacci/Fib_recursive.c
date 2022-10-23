#include <stdio.h>

int Fib (int n)
{
    if (n == 0 || n == 1) {
        return n;
    }

    return Fib(n - 1) + Fib(n - 2);
}

int main(void)
{
    printf("%d", Fib(10));

    return 0;
}