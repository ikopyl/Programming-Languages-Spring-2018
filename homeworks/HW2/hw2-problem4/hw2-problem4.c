#include <stdio.h>

//const int K = 1000;                    // system-dependent constant
const int K = 1;                    // system-dependent constant

int ibs(int *, int, int);

int rbs(int *, int, int, int);
//int rbs(int *, int, int);

void initializeArray(int *, int);
void binarySearchTest(int *, int);



int main() 
{
//    printf("%f\n", log2(9));
//    printf("%d\n", (int) log2(9));         // floor of log2(9)


//    int sizeOfArray = 65536;               // 2^16
    int sizeOfArray = 6;               // debugging rbs
    int a[sizeOfArray];

    initializeArray(a, sizeOfArray);
    binarySearchTest(a, sizeOfArray);

    printf("%d\n", 10/2);
    printf("%d\n", 9/2);
    printf("%d\n", 1 % 2);

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
//            if (bs(a, n, i) != i)

            if (rbs(a, 0, n, i) != i)
                printf("\ti = %d\ta[i] = %d\trbs = %d\n", i, a[i], rbs(a, 0, n, i));
//                puts("ERROR");
        }
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
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return rbs(a, low, mid-1, value);
        else
            return rbs(a, mid+1, high, value);
    }

    return -1;
}


