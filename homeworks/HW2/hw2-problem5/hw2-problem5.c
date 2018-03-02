#include <stdio.h>
#include <zconf.h>
#include <time.h>

int Frec(int);
int Fit(int);

int findN10();
double benchmarkFibFunction(int (*f)(int), int);       // using the function pointer to avoid unnecessary code repetition


int main()
{
    puts("Depending on the compiler optimizations, the results may vary.");

    printf("Running time of Fit(35) = %f seconds.\n", benchmarkFibFunction(Fit, 35));
    printf("Running time of Frec(35) = %f seconds.\n", benchmarkFibFunction(Frec, 35));


    return 0;
}

/**
 * Function measures the performance of both Fibonacci functions.
 *
 * @param f accepts any function that takes and returns an int value.
 * @param n int value that will be passed as a parameter to f
 * @return returns running time in seconds of function f for input n.
 */
double benchmarkFibFunction(int (*f)(int), int n)
{
    clock_t start_t, end_t = 0;
    start_t = clock();
    (*f)(n);
    end_t = clock();

    return (double) (end_t - start_t)/CLOCKS_PER_SEC;
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

