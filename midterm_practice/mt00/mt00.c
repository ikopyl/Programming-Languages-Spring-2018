#include <stdio.h>

int rsum(int);
int isum(int);

int main()
{

    unsigned char num00 = 0b00000000u;
    unsigned char num01 = 0b00000001u;
    unsigned char num02 = 0b00000010u;
    unsigned char num03 = 0b00000011u;
    unsigned char num04 = 0b00000100u;

    unsigned char numWhatever = 0b00111000u;

    unsigned char num65 = 0b01000001u;  // 65 == A == 2^6 + 2^0

    printf("num00 = %u\n", num00);
    printf("num01 = %u\n", num01);
    printf("num02 = %u\n", num02);
    printf("num03 = %u\n", num03);
    printf("num04 = %u\n", num04);

    printf("num65 = %c\n", num65);
    printf("isum(num65) == %d\n", isum(num65));
    printf("rsum(num65) == %d\n", rsum(num65));


    printf("numWhatever = %u\n", numWhatever);
    printf("isum(numWhatever) == %d\n", isum(numWhatever));
    printf("rsum(numWhatever) == %d\n", rsum(numWhatever));

    return 0;
}

int rsum(int num)
{
    int numberOfBits = 0;

    if (num & 1 == num)
        return num;

    numberOfBits += (num >> 1) & 1;
    numberOfBits += rsum(num >> 1);

    return numberOfBits;
}

int isum(int num)
{
    int sumOfBits = 0;
    int numberOfBits = sizeof(num) * 8;

    for (int i = 0; i < numberOfBits; i++)
        sumOfBits += ((num >> i) & 1);

    return sumOfBits;
}