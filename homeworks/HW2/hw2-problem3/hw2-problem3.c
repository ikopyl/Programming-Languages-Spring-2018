#include <stdio.h>

unsigned int reduce(int *, unsigned int);
void findTop3MaxValues(int *, unsigned int, int *, int *, int *);
unsigned int moveZeroesToEndOfArray(int *, unsigned int);

int main()
{

    int max1, max2, max3;
    max1 = max2 = max3 = 0;

    int a[16] = { 9, 1, 1, 6, 7, 1, 2, 3, 3, 5, 6, 6, 6, 6, 7, 9 };
    findTop3MaxValues(a, 16, &max1, &max2, &max3);

    printf("%d %d %d", max1, max2, max3);

    return 0;
}

unsigned int reduce(int * a, unsigned int n)
{


    return moveZeroesToEndOfArray(a, n);
}

/**
 * Finding the first 3 maximum values of an array.
 */
void findTop3MaxValues(int * a, unsigned int n, int *max1, int *max2, int *max3)
{
    *max1 = *max2 = *max3 = 0;
    for (int i = 0; i < n; i++)
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