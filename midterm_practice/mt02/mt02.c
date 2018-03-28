#include <stdio.h>
#include <math.h>
#include "functions.h"

char copyReverse(char, unsigned char);
char copyReverseRecursive(char, unsigned char, unsigned char);

int main()
{

    puts("");

    char n0 = 3;
    printf("%d\n", n0);
    printCharBitPattern(n0);

    char result = copyReverse(n0, 3);
    printf("%d\n", result);
    printCharBitPattern(result);

    puts("");

    char n1 = 3;
    printf("%d\n", n0);
    printCharBitPattern(n0);

    char result1 = copyReverse(n1, 7);
    printf("%d\n", result1);
    printCharBitPattern(result1);

    char result2 = copyReverseRecursive(n1, 7, 0);
    printf("%d\n", result2);
    printCharBitPattern(result2);
    return 0;
}

char copyReverse(char m, unsigned char n)
{
    char k = 0;

    while (n--) {
        k += (m & 1);
        k = k << 1;
        m = m >> 1;
    }
    return k;
}

char copyReverseRecursive(char m, unsigned char n, unsigned char k)
{
    if (n == 0)
        return k;
    else 
    {
        k += (m & 1);
        k = k << 1;
        m = m >> 1;
        n--;
        return copyReverseRecursive(m, n, k);
    }
}
