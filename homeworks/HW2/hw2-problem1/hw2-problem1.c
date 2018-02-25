#include <stdio.h>
#include "functions.h"

unsigned int maxlen(int *, unsigned int);

int main()
{
    int a[13] = { 1, 1, 1, 2, 3, 3, 5, 6, 6, 6, 6, 7, 9 };
    printf("Array a: ");
    printIntArray(a, sizeof(a));
    printf("Max sequence length of array a = %d\n\n",
           maxlen(a, 13));

    int b[0] = {};                              // testing the edge case with an empty array
    printf("Array b: ");
    printIntArray(b, sizeof(b));
    printf("Max sequence length of array b = %d\n\n",
           maxlen(b, 0));

    int c[1] = { 12 };                          // testing the edge case with just 1 element in the array
    printf("Array c: ");
    printIntArray(c, sizeof(c));
    printf("Max sequence length of array c = %d\n\n",
           maxlen(c, 1));

    int d[12] = { -49, -15, 16, 16, 16, 17, 17, 18, 18, 18, 19, 20 };
    printf("Array d: ");
    printIntArray(d, sizeof(d));
    printf("Max sequence length of array d = %d\n\n",
           maxlen(d, 12));

    return 0;
}

unsigned int maxlen(int *a, unsigned int n)
{
    if (n < 2)                                  // handling the edge cases
        return n;

    unsigned int max_count, current_count, i;
    i = max_count = 0;
    current_count = 1;

    printf("\ta[%d]=%d; \tcurrent_count=%d; \tmax_count=%d\n", i, a[i], current_count, max_count);

    for (i = 1; i < n; ++i)
    {
        if (a[i] == a[i-1])                     // counting the current sequence
            current_count++;
        else                                    // reseting the counter for the new sequence
        {
            if (current_count > max_count)      // saving the max count
                max_count = current_count;
            if (max_count > n - i)              // no need to continue if max_count is sufficiently large
                break;
            current_count = 1;                  // reseting the counter
        }

        printf("\ta[%d]=%d; \tcurrent_count=%d; \tmax_count=%d\n", i, a[i], current_count, max_count);
    }
    return max_count;
}
