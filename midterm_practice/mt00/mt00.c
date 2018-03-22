#include <stdio.h>

int rsum1(int);
int rsum2(int);
int isum1(int);
int isum2(int);
int isum3(int);

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
    printf("isum1(num65) == %d\n", isum1(num65));
    printf("isum2(num65) == %d\n", isum2(num65));
    printf("isum3(num65) == %d\n", isum3(num65));
    printf("rsum1(num65) == %d\n", rsum1(num65));
    printf("rsum2(num65) == %d\n", rsum2(num65));


    printf("numWhatever = %u\n", numWhatever);
    printf("isum1(numWhatever) == %d\n", isum1(numWhatever));
    printf("isum2(numWhatever) == %d\n", isum2(numWhatever));
    printf("isum3(numWhatever) == %d\n", isum3(numWhatever));
    printf("rsum1(numWhatever) == %d\n", rsum1(numWhatever));
    printf("rsum2(numWhatever) == %d\n", rsum2(numWhatever));


    int n1 = 6;
    int n2 = -1;

    printf("n1 = %d\n", n1);
    printf("isum3(n1) == %d\n", isum3(n1));
    printf("rsum2(n1) == %d\n", rsum2(n1));
    printf("n2 = %d\n", n2);
    printf("isum3(n2) == %d\n", isum3(n2));
    printf("rsum2(n2) == %d\n", rsum2(n2));

    return 0;
}

int rsum1(int num)
{
    if (num == 0)
        return 0;
    else
        return 1 + rsum1((num - 1) & num);       // Brian Kernigan's Algorithm
}

int rsum2(int num)
{
    if (num == 0)
        return 0;
    else
        return (num & 1) + rsum2(num >> 1);
}

int isum1(int num)
{
    int sumOfBits = 0;
    int numberOfBits = sizeof(num) * 8;

    for (int i = 0; i < numberOfBits; i++)
        sumOfBits += ((num >> i) & 1);

    return sumOfBits;
}

int isum2(int num)
{
    int sumOfBits = 0;
    while (num)
    {
        sumOfBits += num & 1;
        num = num >> 1;
    }
    return sumOfBits;
}

int isum3(int num)
{
    int sumOfBits = 0;
    while (num)
    {
        sumOfBits++;
        num = (num - 1) & num;
    }
    return sumOfBits;
}
