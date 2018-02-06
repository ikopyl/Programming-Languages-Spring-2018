/********************************
 * Hasan Niftiyev
 * CSC 600 - Homework 2
Problem 4: Integer Plot Function

Write a program BigInt(n) that displays an arbitrary positive integer n using big
characters of size 7x7, as in the following example for BigInt(170):
   @@ @@@@@@@ @@@@@
  @@@      @@ @@ @@
   @@      @@ @@ @@
   @@      @@ @@ @@
   @@      @@ @@ @@
   @@      @@ @@ @@
 @@@@@@    @@ @@@@@
 
 * ******************************/


#include <iostream>
#include <string>
#define SIZE 7

using namespace std;

void bigInt (int);
string digitPrint(int[],int);

int main (){
 
 bigInt(1234567890);

 return 0;

}



void bigInt (int number){

	int reverseDigits[SIZE];
	int number_length = 0;

  // breaking it up into each digit and save them in array in reverse order
	while(number != 0 ){
    //last digit
		reverseDigits[number_length++] = number % 10;
		number /= 10; // move on to next digit 
	}

		cout << digitPrint(reverseDigits,number_length) << "\n" << endl;
	
}

// function that passes structured digits to print
string digitPrint(int array[], int length){

  // sample dataset
  string digitMatrix[SIZE][10] = {
        {" @@@@@ ","  @@   "," @@@@@@"," @@@@@@","   @@@@","@@@@@@","  @@@@  ","@@@@@@@","@@@@@@@","@@@@@@@"},
        {"@@   @@"," @@@   ","@    @@","@    @@","  @@ @@","@@     "," @@    ","     @@","@@   @@","@    @@"},
        {"@@   @@","  @@   ","      @","     @@"," @@  @@","@@     ","@@     ","    @@ ","@@   @@","@    @@"},
        {"@@   @@","  @@   ","  @@@@@"," @@@@@@","@@   @@","@@@@@@@","@@     ","   @@  ","@@@@@@@"," @@@@@@"},
        {"@@   @@","  @@   "," @     ","     @@","@@@@@@@","     @@","@@@@@@@","  @@   ","@@   @@","     @@"},
        {"@@   @@","  @@   "," @@    ","@    @@","     @@","     @@","@    @@"," @@    ","@@   @@","     @@"},
        {" @@@@@ ","@@@@@@ "," @@@@@@","@@@@@@@","     @@","@@@@@@@"," @@@@@@","@@     ","@@@@@@@"," @@@@@@"}             
    };

  string output = "";
  string number= "";

      //iterate through each line
  for (int line = 0; line < SIZE; line++){
    // to have each line printed in nice format
    number += "\n" ;
    //iterate though each digit
    for (int digit = length - 1; digit >= 0 ; digit --){

      output = digitMatrix[line][array[digit]] + " ";
      number += output;
    }
  }

    return number;
}


