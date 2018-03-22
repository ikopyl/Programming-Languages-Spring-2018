#include <stdio.h>

int main()
{

    unsigned char num00 = 0b00000000u;
    unsigned char num01 = 0b00000001u;
    unsigned char num02 = 0b00000010u;
    unsigned char num03 = 0b00000011u;
    unsigned char num04 = 0b00000100u;

    unsigned char num65 = 0b01000001u;  // 65 == A == 2^6 + 2^0

    printf("num00 = %u\n", num00);
    printf("num01 = %u\n", num01);
    printf("num02 = %u\n", num02);
    printf("num03 = %u\n", num03);
    printf("num04 = %u\n", num04);

    printf("num65 = %c\n", num65);

    return 0;
}