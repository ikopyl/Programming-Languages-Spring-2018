#include <stdio.h>
#include "functions.h"

int main()
{

    char n0 = 0;
    char n1 = 1;
    char n2 = 2;
    char n3 = 3;
    unsigned char n4 = 128;

    genericPrintNumBitPattern(n0, 8);
    genericPrintNumBitPattern(n1, 8);
    genericPrintNumBitPattern(n2, 8);
    genericPrintNumBitPattern(n3, 8);
    
    genericPrintNumBitPattern(n4, 8);

    return 0;
}

