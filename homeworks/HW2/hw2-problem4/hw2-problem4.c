#include <stdio.h>
#include <math.h>
#include "functions.h"

// const unsigned long long K = 1000000000000000000;              // system-dependent constant, 100k with bs-passthrough is 4sec.
const unsigned long long K = 10;              // system-dependent constant, 100k with bs-passthrough is 4sec.

int bs(int *, unsigned int, int);

int iterativeBinarySearch(int *, unsigned int, int);



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

int iterativeBinarySearch(int *a, unsigned int n, int item) {

    int itemLocation = -1;
    unsigned int low, mid, high;
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



int bs(int *a, unsigned int n, int item)
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
    unsigned long long j;
    unsigned int i;
    for (j = 0; j < K; j++)
        for (i = 0; i < n; i++) {
            int something;
            if ((something = iterativeBinarySearch(a, n, a[i])) != i) {
                puts("ERROR");
                printf("\tERROR: %d\ti == %d\ta[i] == %d\t\n", something, i, a[i]);
            }
            else
                printf("bs = %d\ti == %d\n", something, i);
//            if (bs(a, n, i) != i)
        }

}
