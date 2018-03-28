#include <stdio.h>
#include <math.h>
#include "functions.h"

char copyReverse(char, unsigned char);

int main()
{

    puts("");

    char n0 = 3;
    printf("%d\n", n0);
    printCharBitPattern(n0);

    char result = copyReverse(n0, 3);
    printf("%d\n", result);
    printCharBitPattern(result);



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
