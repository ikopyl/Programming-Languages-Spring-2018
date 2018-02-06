/********************************
 * Hasan Niftiyev
 * CSC 600 - Homework 2
 * Problem 3: Array Processing
 Array processing (elimination of three largest values) (one of many array reduction
problems)
The array a(1..n) contains arbitrary integers. Write a function reduce(a,n) that reduces
the array a(1..n) by eliminating from it all values that are equal to three largest different
integers. For example, if a=(9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9) then three largest different
integers are 6,7,9 and after reduction the reduced array will be a=(1,1,1,2,3,3,5), n=7. The
solution should have time complexity O(n).
 * ******************************/

#include <iostream>

using namespace std;

int* reduce(int* , int* , int);
int* threeLargetsElement(int* , int);

int main(){

	// test case given by instructor
	int array[16] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
	int * reducedArray = new int[16];
	int * maxList = threeLargetsElement(array,16);
	reducedArray = reduce(array,maxList,16);

	for (int index = 0; index < 16 && (reducedArray[index] !=0) ; index++){
		cout << reducedArray[index] << " " ;
	}
	// move terminal cursor to new line
	cout << endl;

	return 0;
}

// A function that reduce the size of array by removing 
// largest three elements from the list.
int* reduce(int * array , int * maxList, int size){

	int* dummyArray = new int[size-3]; 
	int dummyIndex = 0;

	for (int index = 0; index < size; index++){
		if (array[index] != maxList[0] && array[index] != maxList[1] && array[index] != maxList[2]){
			// if an element is not one of maxList then add it to dummyArray and keep special index
			dummyArray[dummyIndex++] = array[index];
		}
	}

	return dummyArray;
}



// created an array with three elements where
// first , second and third elements are the respectively maximum
//of array in a sorted form.
int* threeLargetsElement(int* array, int size){
	// initialized elements to zero by asuming inputs will be positive. 
	// use -INT_MAX for minimum value if negative input will be a test case
	int* maxList = new int[3]();
	
		// iterate thorugh each element and find max of three
	for (int index = 0; index < size ; index++){

		if (array[index]> maxList[0]){
			maxList[2]=maxList[1]; maxList[1]=maxList[0]; maxList[0]=array[index];
		}

		else if (array[index] < maxList[0] && array[index]> maxList[1]){
			maxList[2] = maxList[1]; maxList[1] = array[index];
		}
		else if (array[index] < maxList[1] && array[index]> maxList[2]){
			maxList[2] = array[index];
		}
	}


	return maxList;
}
