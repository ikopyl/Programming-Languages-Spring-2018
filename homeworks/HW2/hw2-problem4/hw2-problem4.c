#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"

// const unsigned long long K = 1000000000000000000;              // system-dependent constant, 100k with bs-passthrough is 4sec.
const int K = 10;              // system-dependent constant, 100k with bs-passthrough is 4sec.

int bs(int *, int, int);

void initializeArray(int *, int);
void binarySearchTest(int *, int);



int main() 
{
    printf("%f\n", log2(9));
    printf("%d\n", (int) log2(9));         // floor of log2(9)


    int sizeOfArray = 65536;               // 2^16
    int a[sizeOfArray];

    initializeArray(a, sizeOfArray);

//    for (int i = 0; i < sizeOfArray; i++)
//        printf("%d ", a[i]);
//    printf("\n");


    binarySearchTest(a, sizeOfArray);

    return 0;
}

void initializeArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}

void binarySearchTest(int *a, int n)
{
    int i, j;
    for (j = 0; j < K; j++)
        for (i = 0; i < n; i++) {
            if (bs(a, n, i) != i)
                puts("ERROR");
        }
}

/**
 * Iterative implementation of Binary Search
 */
int bs(int *a, int n, int item)
{
    int itemLocation = -1;
    int low, mid, high;
    low = 0;
    high = n;

    while (high >= low && itemLocation == -1)
    {
        mid = (low + high) / 2;
        if (item == a[mid])
            itemLocation = mid;
        else if (item < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return itemLocation;
}
