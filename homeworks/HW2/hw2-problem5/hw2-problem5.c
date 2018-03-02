#include <stdio.h>

int Frec(int);
unsigned long long int Fit(unsigned long long int);

int main()
{

    return 0;
}

/**
 * Recursive implementation of function
 * computing Fibonacci numbers.
 */
int Frec(int n)
{
    return n <= 1 ? n : Frec(n - 1) + Frec(n - 2);
}

/**
 * Iterative implementation of function
 * computing Fibonacci numbers.
 */
unsigned long long int Fit(unsigned long long int n)
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
