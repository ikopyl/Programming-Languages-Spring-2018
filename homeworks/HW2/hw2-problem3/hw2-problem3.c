#include <stdio.h>

unsigned int reduce(int *, unsigned int);
unsigned int moveZeroesToEndOfArray(int *, unsigned int);

int main()
{

    return 0;
}

unsigned int reduce(int * a, unsigned int n)
{

    return moveZeroesToEndOfArray(a, n);
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
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            a[indexOfNullValue++] = a[i];

    sizeOfReducedArray = indexOfNullValue;

    // nullifying the remaining part of the array
    while (indexOfNullValue < n)
        a[indexOfNullValue++] = 0;

    // returning the size of reduced array
    return sizeOfReducedArray;
}