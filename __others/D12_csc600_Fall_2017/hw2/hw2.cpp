#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

/*1. Plateau program
input: an array of arbitrary size
processing:
	1. assume array elements are of type int
	2. get length of array
	3. traverse array
	4. compare element of current index with prior element
	5. if they are the same value, count++
	6. if they are different values, continue
	7. compare count to max each time count isn't incremented
	8. if count > max, max = count
	9. return max
output: the max length of the longest sequence of identical numbers */
int getSeqLength(int arr[],int size){
	int count = 1;
	int max = 0;

	for (int i=1;i<size;i++){
		if(arr[i] == arr[i-1]){
			count++;
			if(max < count){
				max = count;
			}
		}else{
			count = 1;
		}
	}
    return max;
}


//2. Parabolic approximation

//3. Array processing
// print array function
void printArray(int arr[],int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	cout << "\n";
}

void getLargestThreeNumbers(int arr[], int threeHighest[], int size){
	cout << "size:" << size << "\n";
	int x = 0, y = 0, z = 0;

	//find the largest three elements
	for (int i=0; i<size; i++){
		if(arr[i] > threeHighest[2] && arr[i] != threeHighest[2] && arr[i] != threeHighest[1] && arr[i] != threeHighest[0]) {
			if(arr[i] > threeHighest[1]) {
				if(arr[i] > threeHighest[0]){
					threeHighest[2] = threeHighest[1];
					threeHighest[1] = threeHighest[0];
					threeHighest[0] = arr[i];
				} else {
					threeHighest[2] = threeHighest[1];
					threeHighest[1] = arr[i];
				}
			} else {
				threeHighest[2] = arr[i];
			}
		}
	}
	printArray(threeHighest,3); 
}

void reduceArray(int arr[], int size){
	if(size <= 3){
		arr[0] = '\0';
	}else {
		int threeHighest[3] = {INT_MIN, INT_MIN, INT_MIN};
		int j = 0;

		getLargestThreeNumbers(arr,threeHighest,size);

		for(int i = 0; i < size; i++){
			if(!((threeHighest[0] == arr[i]) || (threeHighest[1] == arr[i]) || (threeHighest[2] == arr[i]))){
				arr[j] = arr[i];
				j++;
			}
		}
		arr[j] = '\0';
	}
}

//4. Integer plot function
void makeItBig(int n) {
	std::vector<int> v;
	string row = "";

	// construct an array of single digits (as a vector)
	while (n > 0){
		int number = n%10;
		n /= 10;
		v.push_back(number);
	}

	// columns correspond to the desired number, so we can draw whatever we want by iterating through the rows at that column index
	string bigNumMatrix[7][10] = {
		{"  #####  ", " ## ", "  #####  ", " ######  ", " ##   ## ", " ####### ", " ##       ", " ####### ", "  ######  ", "  #####  "},
		{" ##   ## ", " ## ", " ##   ## ", "      ## ", " ##   ## ", " ##      ", " ##       ", "      ## ", " ##    ## ", " ##   ## "},
		{" ##   ## ", " ## ", "     ##  ", "      ## ", " ##   ## ", " ##      ", " ##       ", "      ## ", " ##    ## ", " ##   ## "},
		{" ##   ## ", " ## ", "    ##   ", "   ####  ", " ####### ", " ####### ", " #######  ", "      ## ", "  ######  ", "  ###### "},
		{" ##   ## ", " ## ", "  ##     ", "      ## ", "      ## ", "      ## ", " ##    ## ", "      ## ", " ##    ## ", "      ## "},
		{" ##   ## ", " ## ", " ##      ", "      ## ", "      ## ", "      ## ", " ##    ## ", "      ## ", " ##    ## ", "      ## "},
		{"  #####  ", " ## ", " ####### ", " ######  ", "      ## ", " ####### ", "  ######  ", "      ## ", "  ######  ", "      ## "}
	};

	// output loop
	for(int i=0;i<7;i++){
		for(int j=v.size()-1;j>=0;j--){
			row += bigNumMatrix[i][v[j]];
		}
		cout << row << "\n";
		row = "\0";
	}
}

//5. Iteration vs recursion
// need to fill the array first
void fill(int arr[], int size){
	for(int i=0;i<=size;i++){
		arr[i] = i;
		arr[i + 1] = '\0';
	}
}

// iterative binary search (from Algorithms Unlocked)
int iterativeBinarySearch(int arr[], int find, int size){
	int low = 0;
	int high = size - 1;

	while(low <= high) {
		int mid = (low+high)/2;

		if(find < arr[mid]){
			high = mid - 1;
		}else if(find > arr[mid]){
			low = mid + 1;
		}else{
			return arr[mid];
		}
	}
	return -1;
}

// recursive binary search (from Algorithms Unlocked)
int recursiveBinarySearch(int arr[], int low, int high, int find){
	int mid = (low + high)/2;
	if(low > high){
		return -1;
	}

	if(find < arr[mid]){
		recursiveBinarySearch(arr, low, mid-1, find);
	}
	else if(find > arr[mid]){
		recursiveBinarySearch(arr, mid+1, high, find);
	}
	else{
		return arr[mid];
	}
	return -1;
}


// testing
int main(int argc, char** argv){
	// problem 1
	int arr1[] = {1,1,1,2,3,3,5,6,6,6,6,7,9};
	int size = sizeof(arr1)/sizeof(arr1[0]);
	int maxLength = 0;
	maxLength = getSeqLength(arr1,size);

	cout << "Problem 1:\n";
	cout << "arrSize: " << size << "\n";
	cout << "max length: " << maxLength << "\n\n";
	
	// problem 3
	reduceArray(arr1,size);
	
	cout << "Problem 3:\n";
	printArray(arr1,size);

	// problem 4
	cout << "Problem 4:\n";
	makeItBig(666);

	// problem 5
	cout << "Problem 5:\n";
	int arr2[100000];
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	fill(arr2,100000);

	clock_t start = clock();
	time_t current = time(0);
	iterativeBinarySearch(arr2, 120, size2);
	time_t after = time(0);
	clock_t end = clock();
	std::cout << "Iterative: " << end - start << std::endl;

	start = clock();
	current = time(0);
	recursiveBinarySearch(arr2, 0, 100000, 120);
	after = time(0);
	end = clock();
	std::cout << "Recursive: " << end - start << std::endl;

	return 0;
}



