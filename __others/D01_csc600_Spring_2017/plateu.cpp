/********************************
 * Hasan Niftiyev
 * CSC 600 - Homework 2
 
 Problem 1: Plateu prgram

 The array a(1..n) contains sorted integers. Write a function maxlen(a,n) that returns the
length of the longest sequence of identical numbers (for example, if
a=(1,1,1,2,3,3,5,6,6,6,6,7,9) then maxlen returns 4 because the longest sequence 6,6,6,6
contains 4 numbers. Write a demo main program for testing the work of maxlen. Explain
your solution, and insert comments in your program. The solution should have time
complexity O(n).
 * ******************************/


#include <iostream>
#include <string>

using namespace std;

// A function to check longest sequence in an array
// Assuming the valid Array will be given.
int maxlen(int array[] , int size ){

	int counter = 1;
	int maxCount = 1;

	// start iterating from second element by comparing 
	// with previous element.
	for (int index=1 ; index < size ; index ++){

		if (array[index] ==  array[index-1]){       
			counter++;                              
			if (counter > maxCount)
				maxCount = counter;
		}
		
		else                                         
			counter = 1;
	}

	return maxCount;
}


int main (){
 
 int array[13]={1,1,1,2,3,3,5,6,6,6,6,7,9};
 int size = 13;

 cout << "The longest sequence is :" << maxlen(array,size) << endl;

 return 0;

}
