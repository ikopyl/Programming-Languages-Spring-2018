#include <stdio.h>

void BigInt(unsigned int);


/**
 * Digits are stored as the bit patterns
 * of 8-bit unsigned integer (char) numbers.
 *
 * Each digit requires just 8 bytes of storage -
 * which is polynomially smaller than the storage
 * in brute-force approach where each digit is
 * represented by a 2D array of 8x8 characters,
 * with 64 bytes of storage per digit.
 *
 */
const unsigned char digits[8][10] = {

        {       // row 0 of all 10 digits
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u,
                0b00000000u
        },

        {       // row 1 of all 10 digits
                0b00111110u,
                0b00001100u,
                0b00011110u,
                0b00011110u,
                0b00000110u,
                0b00111111u,
                0b00011110u,
                0b01111111u,
                0b00011110u,
                0b00011110u
        },

        {       // row 2 of all 10 digits
                0b01100011u,
                0b00011100u,
                0b00110011u,
                0b00110011u,
                0b00001110u,
                0b00110000u,
                0b00110011u,
                0b00000011u,
                0b00110011u,
                0b00110011u
        },

        {       // row 3 of all 10 digits
                0b01100011u,
                0b00001100u,
                0b00110011u,
                0b00000011u,
                0b00010110u,
                0b00110000u,
                0b00110000u,
                0b00000110u,
                0b00110011u,
                0b00110011u
        },

        {       // row 4 of all 10 digits
                0b01100011u,
                0b00001100u,
                0b00000110u,
                0b00001100u,
                0b00110110u,
                0b00111110u,
                0b00111110u,
                0b00001100u,
                0b00011110u,
                0b00011111u
        },

        {       // row 5 of all 10 digits
                0b01100011u,
                0b00001100u,
                0b00001100u,
                0b00000011u,
                0b01100110u,
                0b00000011u,
                0b00110011u,
                0b00011000u,
                0b00110011u,
                0b00000011u
        },

        {       // row 6 of all 10 digits
                0b01100011u,
                0b00001100u,
                0b00011000u,
                0b00110011u,
                0b01111111u,
                0b00000011u,
                0b00110011u,
                0b00110000u,
                0b00110011u,
                0b00110011u
        },

        {       // row 7 of all 10 digits
                0b00111110u,
                0b00111111u,
                0b00111111u,
                0b00011110u,
                0b00000110u,
                0b00111110u,
                0b00011110u,
                0b01100000u,
                0b00011110u,
                0b00011110u
        }

};

int main()
{

    return 0;
}

void BigInt(unsigned int n) 
{

}
