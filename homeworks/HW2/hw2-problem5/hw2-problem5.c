#include <stdio.h>

int Frec(int);
int Fit(int);

int findN10();
double benchmarkFibFunction(int (*f)(int), int);       // using the function pointer to avoid unnecessary code repetition


int main()
{
    puts("Depending on the compiler optimizations, the results may vary.");

    benchmarkFibFunction(Fit, 10);
    benchmarkFibFunction(Frec, 10);


    return 0;
}

/**
 * Function measures the performance of both Fibonacci functions.
 *
 * @param f accepts any function that takes and returns an int value.
 * @param n int value that will be passed as a parameter to f
 * @return
 */
double benchmarkFibFunction(int (*f)(int), int n)
{
    unsigned long result = 0;

    result = (*f)(n);
    printf("Fib(%d) = %lu\n", n, result);

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
int Fit(int n)
{
    int first, second, temp, i;
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

