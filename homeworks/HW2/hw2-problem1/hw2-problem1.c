#include <stdio.h>
#include <assert.h>
#include "functions.h"

unsigned int maxlen(int *, unsigned int);

int main()
{
    int result = 0;

    int a[13] = { 1, 1, 1, 2, 3, 3, 5, 6, 6, 6, 6, 7, 9 };
    printf("Array a:    ");
    printIntArray(a, sizeof(a));

    result = maxlen(a, 13);
    printf("Max sequence length of array a = %d\n\n", result);
    assert(result == 4);


    int b[0] = {};                              // testing the case: an empty array
    printf("Array b:    ");
    printIntArray(b, sizeof(b));

    result = maxlen(b, 0);
    printf("Max sequence length of array b = %d\n\n", result);
    assert(result == 0);


    int c[1] = { 12 };                          // testing the case: 1 element in the array
    printf("Array c:    ");
    printIntArray(c, sizeof(c));

    result = maxlen(c, 1);
    printf("Max sequence length of array c = %d\n\n", result);
    assert(result == 1);


    // testing the early loop exit:
    int d[6] = { 16, 16, 16, 18, 18, 20 };
    printf("Array d:    ");
    printIntArray(d, sizeof(d));

    result = maxlen(d, 6);
    printf("Max sequence length of array d = %d\n\n", result);
    assert(result == 3);


    int e[2] = { 0, 0 };                        // testing the case: 2 elements with the same value
    printf("Array e:    ");
    printIntArray(e, sizeof(e));

    result = maxlen(e, 2);
    printf("Max sequence length of array e = %d\n\n", result);
    assert(result == 2);


    int f[2] = { 0, 1 };                        // testing the case: 2 elements with different values
    printf("Array f: ");
    printIntArray(f, sizeof(f));

    result = maxlen(f, 2);
    printf("Max sequence length of array f = %d\n\n", result);
    assert(result == 1);


    int g[4] = { 1, 2, 3, 3 };      // testing the case: the longest sequence is at the end of array
    printf("Array g:    ");
    printIntArray(g, sizeof(g));

    result = maxlen(g, 4);
    printf("Max sequence length of array g = %d\n\n", result);

    return 0;
}

unsigned int maxlen(int *a, unsigned int n)
{
    if (n < 2)                                      // handling the edge cases of arrays of size 0 and 1
        return n;

    unsigned int max_count, current_count, i;
    i = max_count = 0;
    current_count = 1;

    printf("    a[%d]=%d; \tcurrent_count=%d; \tmax_count=%d\n",
           i, a[i], current_count, max_count);

    for (i = 1; i < n; ++i)
    {
        if (a[i] == a[i-1])         // counting the current sequence
        {
            current_count++;

            // checking whether the longest sequence is at the end of array
            if(i == n-1 && current_count > max_count)
                max_count = current_count;
        }
        else            // starting the count of the new sequence:
        {
            if (current_count > max_count)
                max_count = current_count;

            // exit the loop if max_count is sufficiently large:
            if (max_count >= n-i)
                break;
            current_count = 1;
        }

        printf("    a[%d]=%d; \tcurrent_count=%d; \tmax_count=%d\n",
               i, a[i], current_count, max_count);
    }
    return max_count;
}
