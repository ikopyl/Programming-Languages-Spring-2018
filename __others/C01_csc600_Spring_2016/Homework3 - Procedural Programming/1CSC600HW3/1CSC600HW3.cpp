#include <iostream>
using namespace std;

int maxlen(int theArray[], int size) {
	int largest=0, count=1, previous=0, i;

	for(i=1;i<size-1;i++)
	{
		//count is incremented if 2 integers in the iterative process are the same.
		if(theArray[previous]==theArray[i])
		{
			count++;
			//if count exceeds the largest number, largest will copy the value at count.
			if(largest<count)
				largest=count;
		}
		else
		{
			//if the previous and currrent numbers arent the same, count will reset.
			count=1;
		}
		//increments previous for comparison with current element
		previous = i;
	}
	return largest;
}
int main(void) {
	int n = 13;
	int theArray[13] = {1,1,1,2,3,3,5,6,6,6,6,7,9};
	//prints out the returning max length from the function maxlen
	cout << "longest sequence = " << maxlen(theArray, n) << endl;
}
