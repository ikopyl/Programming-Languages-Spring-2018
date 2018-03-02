#include <stdio.h>
#include <zconf.h>
#include <time.h>

int Frec(int);
int Fit(int);

double findN(int *);

// using the function pointer to avoid unnecessary code repetition:
double benchmarkFibFunction(int (*f)(int), int);


int main()
{
    puts("Depending on the compiler optimizations, the results may vary. Please wait...");

    int threshold = 10;
    // !!! the value of threshold will become an index of Nth Fibonachi term
    double runningTimeFrec = findN(&threshold);
    printf("N10 = %d\n", threshold);
    printf("Running time of Frec(%d) is %f seconds.\n", threshold, runningTimeFrec);

    double runningTimeFit = benchmarkFibFunction(Fit, threshold);
    printf("Running time of Fit(%d) is %f seconds.\n", threshold, runningTimeFit);

    double speedIncrease = runningTimeFrec / runningTimeFit;

    printf("Running time of Fit(%1$d) is %.2f times faster than running time of Frec(%1$d)",
           threshold, speedIncrease);


    return 0;
}

/**
 * Function that iteratively runs benchmarks against recursive Fibonacci function
 * until the running time exceeds the given time threshold in seconds.
 * @return index of nth Fibonacci term is returned through parameter (dirty hack).
 * @return the time it took to compute nth Fibonacci term.
 */
double findN(int *timeThreshold) {
    int n = 0;
    double runningTime = 0;
    while ((runningTime = benchmarkFibFunction(Frec, ++n)) < *timeThreshold);
    *timeThreshold = n;         // returning the index of nth Fibonacci term through parameter
    return runningTime;
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

    return (double) (end_t - start_t) / CLOCKS_PER_SEC;
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

