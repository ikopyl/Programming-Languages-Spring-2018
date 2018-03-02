#include <stdio.h>
#include <time.h>

#define K 1000                      // system-dependent constant

void initializeArray(int *, int);
int ibs(int *, int, int);
int rbs(int *, int, int, int);
double ibsTest(int *, int);
double rbsTest(int *, int);

int main() 
{
    int sizeOfArray = 65535;        // 2^16-1, staying conservative
    int a[sizeOfArray];

    initializeArray(a, sizeOfArray);

    printf("Running time of iterative Binary Sort: %f seconds.\n", ibsTest(a, sizeOfArray));
    printf("Running time of recursive Binary Sort: %f seconds.\n", rbsTest(a, sizeOfArray));
    puts("Benchmarking is complete!");

    return 0;
}

void initializeArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}

/**
 * Iterative implementation of Binary Search
 */
int ibs(int *a, int n, int value)
{
    int itemLocation = -1;
    int low, mid, high;
    low = 0;
    high = n;

    while (high >= low && itemLocation == -1)
    {
        mid = (low + high) / 2;
        if (value == a[mid])
            itemLocation = mid;
        else if (value < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return itemLocation;
}

/**
 * Recursive implementation of Binary Search
 */
int rbs(int *a, int low, int high, int value)
{
    if (high < low)
        return -1;
    else
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return rbs(a, low, mid-1, value);
        else
            return rbs(a, mid+1, high, value);
    }
}

/**
 * Function for testing the performance
 * of iterative binary search.
 */
double ibsTest(int *a, int n)
{
    clock_t start_t, end_t, running_time = 0;
    int i, j;

    start_t = clock();
    for (j = 0; j < K; j++)
        for (i = 0; i < n; i++)
        {
            if (ibs(a, n, i) != i)
                puts("ERROR");
        }
    end_t = clock();
    running_time += (end_t - start_t);

    return (double) running_time / CLOCKS_PER_SEC;
}

/**
 * Function for testing the performance
 * of recursive binary search.
 */
double rbsTest(int *a, int n)
{
    clock_t start_t, end_t, running_time = 0;
    int i, j;

    start_t = clock();
    for (j = 0; j < K; j++)
        for (i = 0; i < n; i++)
        {
            if (rbs(a, 0, n, i) != i)
                puts("ERROR");
        }
    end_t = clock();
    running_time += (end_t - start_t);

    return (double) running_time / CLOCKS_PER_SEC;
}