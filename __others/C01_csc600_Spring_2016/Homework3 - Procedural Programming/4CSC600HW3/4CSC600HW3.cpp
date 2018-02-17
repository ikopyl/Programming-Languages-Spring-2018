#include <iostream>
#include <cmath>

using namespace std;

//functions called with indicated digit and row number to be printed.
void print0(int row) {
    switch (row) 
    {
        case 0: cout << " @@@@@  "; break;
        case 1: cout << "@@   @@ "; break;
        case 2: cout << "@@   @@ "; break;
        case 3: cout << "@@   @@ "; break;
        case 4: cout << "@@   @@ "; break;
        case 5: cout << "@@   @@ "; break;
        case 6: cout << " @@@@@  "; break;
    }
}
void print1(int row) {
    switch (row) 
    {
        case 0: cout << "  @@   ";  break;
        case 1: cout << " @@@   ";  break;
        case 2: cout << "  @@   ";  break;
        case 3: cout << "  @@   ";  break;
        case 4: cout << "  @@   ";  break;
        case 5: cout << "  @@   ";  break;
        case 6: cout << "@@@@@@ ";  break;
    }
}
void print2(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "@    @@ "; break;
        case 2: cout << "     @@ "; break;
        case 3: cout << "   @@   "; break;
        case 4: cout << " @@@    "; break;
        case 5: cout << "@@      "; break;
        case 6: cout << "@@@@@@@ "; break;
    }
}
void print3(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "     @@ "; break;
        case 2: cout << "     @@ "; break;
        case 3: cout << "   @@@@ "; break;
        case 4: cout << "     @@ "; break;
        case 5: cout << "     @@ "; break;
        case 6: cout << "@@@@@@@ "; break;
    }
}
void print4(int row) {
    switch (row) 
    {
        case 0: cout << "@@   @@ "; break;
        case 1: cout << "@@   @@ "; break;
        case 2: cout << "@@   @@ "; break;
        case 3: cout << "@@@@@@@ "; break;
        case 4: cout << "     @@ "; break;
        case 5: cout << "     @@ "; break;
        case 6: cout << "     @@ "; break;
    }
}
void print5(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "@@      "; break;
        case 2: cout << "@@      "; break;
        case 3: cout << " @@@@@@ "; break;
        case 4: cout << "     @@ "; break;
        case 5: cout << "     @@ "; break;
        case 6: cout << "@@@@@@@ "; break;
    }
}
void print6(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "@@      "; break;
        case 2: cout << "@@      "; break;
        case 3: cout << "@@@@@@@ "; break;
        case 4: cout << "@@   @@ "; break;
        case 5: cout << "@@   @@ "; break;
        case 6: cout << "@@@@@@@ "; break;
    }
}
void print7(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "     @@ "; break;
        case 2: cout << "    @@  "; break;
        case 3: cout << "   @@   "; break;
        case 4: cout << "  @@    "; break;
        case 5: cout << " @@     "; break;
        case 6: cout << "@@      "; break;
    }
}
void print8(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "@@   @@ "; break;
        case 2: cout << "@@   @@ "; break;
        case 3: cout << "@@@@@@@ "; break;
        case 4: cout << "@@   @@ "; break;
        case 5: cout << "@@   @@ "; break;
        case 6: cout << "@@@@@@@ "; break;
    }
}
void print9(int row) {
    switch (row) 
    {
        case 0: cout << "@@@@@@@ "; break;
        case 1: cout << "@@   @@ "; break;
        case 2: cout << "@@   @@ "; break;
        case 3: cout << "@@@@@@@ "; break;
        case 4: cout << "     @@ "; break;
        case 5: cout << "     @@ "; break;
        case 6: cout << "@@@@@@@ "; break;
    }
}


void BigInt(int n) {
    // nSize stores the number of digits in n.
    int nSize = log10 (n) + 1;
    // designates an array to hold the digits of n.
    int nDigits[nSize];
    // stores the digits into the array in reverse.
    for (int i = 0; n != 0; i++) 
    {
        // extract digits from n
        nDigits[i] = n % 10;
        n /= 10;
    }
    
    /* The variable i indicates a row number in which needs
    to be printed when specified by a switch statement. each number is 
    printed row by row and will be looped 7 times in order to print big
    numbers that are of size 7x7. */
    for (int i = 0; i <= 6; i++) 
    {
        //reads the digits one by one and prints the given row correspondingly.
        for (int j = nSize - 1; j >= 0; j--) 
        {   
            //increments through the array of digits in reverse order
            switch (nDigits[j]) 
            {
                case 0: print0(i);  break;
                case 1: print1(i);  break;
                case 2: print2(i);  break;
                case 3: print3(i);  break;
                case 4: print4(i);  break;
                case 5: print5(i);  break;
                case 6: print6(i);  break;
                case 7: print7(i);  break;
                case 8: print8(i);  break;
                case 9: print9(i);  break;
            }
        }
    cout << endl;
    }
}

int main(void) {
    BigInt(170);
    return 0;
}
