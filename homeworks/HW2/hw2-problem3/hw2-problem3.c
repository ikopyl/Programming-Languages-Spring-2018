#include <stdio.h>

unsigned int reduce(int *, unsigned int);
void moveZeroesToEndOfArray(int *, unsigned int);

int main()
{

    return 0;
}

unsigned int reduce(int * a, unsigned int n)
{
    unsigned int reducedArraySize = 0;

    return reducedArraySize;
}

void moveZeroesToEndOfArray(int * a, unsigned int n)
{
    unsigned int indexOfNullValue = 0;

    // moving all non-zero values to the beginning of array
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            a[indexOfNullValue++] = a[i];

    // nullifying the remaining part of array
    while (indexOfNullValue < n)
        a[indexOfNullValue++] = 0;
}