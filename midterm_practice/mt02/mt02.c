#include <stdio.h>
#include <math.h>
#include "functions.h"

char copyReverse(char, unsigned char);
char copyReverseRecursive(char, unsigned char, unsigned char);

void shift(char *, char *, char);

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

    puts("--------------------");
    char m = 73;
    char k = 0;
    char n = 7;
    printf("m = %d, k = %d, n = %d\n", m, k, n);
    printCharBitPattern(m);
    printCharBitPattern(k);

    shift(&m, &k, n);

    printf("m = %d, k = %d, n = %d\n", m, k, n);
    printCharBitPattern(m);
    printCharBitPattern(k);



    return 0;
}

char copyReverse(char m, unsigned char n)
{
    char k = 0;

    while (n--)
    {
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
        return copyReverseRecursive(m >> 1, --n, k << 1);
    }
}

void shift(char *m, char *k, char n)
{
    while(n--)
    {
        *k *= 2;
        *k += (*m % 2);
        *m /= 2;
    }
}
