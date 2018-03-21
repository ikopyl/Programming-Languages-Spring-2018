#include <stdio.h>

int main()
{

    unsigned char num0 = 0b00000000u;
    unsigned char num1 = 0b00000001u;
    unsigned char num2 = 0b00000010u;
    unsigned char num3 = 0b00000011u;
    unsigned char num4 = 0b00000100u;

    unsigned char num65 = 0b01000001u;  // 65 == A == 2^6 + 2^0

    printf("num0 = %u\n", num0);
    printf("num1 = %u\n", num1);
    printf("num2 = %u\n", num2);
    printf("num3 = %u\n", num3);
    printf("num4 = %u\n", num4);

    printf("num65 = %c\n", num65);

    return 0;
}