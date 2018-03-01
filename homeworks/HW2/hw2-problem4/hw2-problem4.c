#include <stdio.h>
#include <math.h>
#include "functions.h"

const unsigned long long K = 1000000000000000000;              // system-dependent constant, 100k with bs-passthrough is 4sec.

unsigned int bs(int *, unsigned int, unsigned int);
void initializeArray(int *, unsigned int);
void binarySearchTest(int *, unsigned int);



int main() 
{
    printf("%f\n", log2(9));
    printf("%d\n", (unsigned int) log2(9));         // floor of log2(9)


    unsigned int sizeOfArray = 10;
    int a[sizeOfArray];
    initializeArray(a, sizeOfArray);
    printIntArray(a, sizeof(a));

    binarySearchTest(a, sizeOfArray);

    return 0;
}

unsigned int bs(int *a, unsigned int n, unsigned int searchedValue)
{

    return 0;
}

void initializeArray(int *a, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
        a[i] = i;
}

void binarySearchTest(int *a, unsigned int n)
{
    unsigned long long counter, j;
    counter = 0;
    unsigned int i;
    for (j = 0; j < K; j++)
        for (i = 0; i < n; i++)
            if (bs(a, n, i) != i)
//                puts("ERROR");
                counter++;
            printf("counter = %llu\n", counter);

}
