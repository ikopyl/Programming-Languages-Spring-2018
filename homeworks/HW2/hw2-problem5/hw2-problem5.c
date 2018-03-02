#include <stdio.h>

int rFib(int);
unsigned long long int iterativeFib(unsigned long long int);

int main()
{

    return 0;
}

/**
 * Recursive implementation of function
 * computing Fibonacci numbers.
 */
int rFib(int n)
{
    return n <= 1 ? n : rFib(n - 1) + rFib(n - 2);
}

unsigned long long int iterativeFib(unsigned long long int n)
{
    unsigned long long int first, second, temp, i;
    first = 0;
    second = 1;

    if (n <= 1)
        return n;
    else
        for (i = 2; i <= n; i++)
        {
            temp = first + second;
            first = second;
            second = temp;
        }
    return temp;        // the n-th value in Fibonacci sequence
}
