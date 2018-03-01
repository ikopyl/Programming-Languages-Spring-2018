#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"

const unsigned long long K = 1000;              // system-dependent constant

int bs(int *, unsigned int, int);
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

int bs(int *a, unsigned int n, int i)
{

    return -1;
}

void initializeArray(int *a, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
        a[i] = i;
}

void binarySearchTest(int *a, unsigned int n)
{
    unsigned int i, j;
    for (j = 0; j > K; j++)
        for (i = 0; i < n; i++) {
            assert((a, n, i) == i);
            if (bs(a, n, i) != i)
                puts("ERROR");

        }

}