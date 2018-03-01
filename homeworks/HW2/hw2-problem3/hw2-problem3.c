#include <stdio.h>
#include "functions.h"

unsigned int reduce(int *, unsigned int);
void findTop3MaxValuesInArray(int *, unsigned int, int *, int *, int *);
void nullifyTop3MaxValuesInArray(int *, unsigned int, int, int, int);
unsigned int moveZeroesToEndOfArray(int *, unsigned int);

int main()
{
    int a[16] = { 9, 1, 1, 6, 7, 1, 2, 3, 3, 5, 6, 6, 6, 6, 7, 9 };

    puts("Original array: ");
    printIntArray(a, sizeof(a));

    int reducedN = reduce(a, 16);

    puts("Reduced array with original bounds: ");
    printIntArray(a, sizeof(a));

    printf("Reduced array with new bounds (n = %d): \n", reducedN);
    printIntArray(a, reducedN * sizeof(int));

    return 0;
}

unsigned int reduce(int * a, unsigned int n)
{
    int max1, max2, max3;
    max1 = max2 = max3 = 0;

    findTop3MaxValuesInArray(a, 16, &max1, &max2, &max3);
    nullifyTop3MaxValuesInArray(a, 16, max1, max2, max3);

    return moveZeroesToEndOfArray(a, n);
}

/**
 * Setting all occurrences of numbers max1, max2, max3 in the array to zero.
 */
void nullifyTop3MaxValuesInArray(int * a, unsigned int n, int max1, int max2, int max3)
{
    unsigned int i;
    for (i = 0; i < n; i++)
        if (a[i] == max1 || a[i] == max2 || a[i] == max3)
            a[i] = 0;
}

/**
 * Finding the first 3 maximum values of an array.
 */
void findTop3MaxValuesInArray(int * a, unsigned int n, int *max1, int *max2, int *max3)
{
    *max1 = *max2 = *max3 = 0;
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > *max1)
        {
            *max3 = *max2;
            *max2 = *max1;
            *max1 = a[i];
        }
        else if (a[i] > *max2 && a[i] < *max1)
        {
            *max3 = *max2;
            *max2 = a[i];
        }
        else if (a[i] > *max3 && a[i] < *max2)
            *max3 = a[i];
    }
}

/**
 * Moves all zeroes to the end of array by copying all non-zero
 * values to the beginning of the array and returning the total
 * amount of non-zero values (i.e. the size of reduced array).
 */
unsigned int moveZeroesToEndOfArray(int * a, unsigned int n)
{
    unsigned int indexOfNullValue, sizeOfReducedArray;
    indexOfNullValue = sizeOfReducedArray = 0;

    // copying all non-zero values to the beginning of array
    unsigned int i;
    for (i = 0; i < n; i++)
        if (a[i] != 0)
            a[indexOfNullValue++] = a[i];

    sizeOfReducedArray = indexOfNullValue;

    // nullifying the remaining part of the array
    while (indexOfNullValue < n)
        a[indexOfNullValue++] = 0;

    // returning the size of reduced array
    return sizeOfReducedArray;
}