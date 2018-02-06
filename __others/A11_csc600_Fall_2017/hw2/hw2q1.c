/**The array a(1..n) contains sorted integers. Write a function maxlen(a,n) that returns the
length of the longest sequence of identical numbers (for example, if
a=(1,1,1,2,3,3,5,6,6,6,6,7,9) then maxlen returns 4 because the longest sequence 6,6,6,6
contains 4 numbers. Write a demo main program for testing the work of maxlen. Explain
your solution, and insert comments in your program. The solution should have time
complexity O(n).
**/

#include <stdio.h>
#include <string.h>

int maxlen(int arr[], int size);

int main()
{
	//create demo array for testing
	int demo[10] = {1,2,3,4,4,5,5,5,6,6};

	printf("The longest sequence contains %d numbers.\n", maxlen(demo,10));
	return 0;
}

int maxlen(int arr[], int size)
{
	int largest = 0, count = 1, i;
	int prev = arr[0];

	//iterate through the array from the second element
	for(i = 1; i < size; i++)
	{
		int cur = arr[i];
		if(prev == cur)
		{
			count++;
			if(count > largest){largest = count;}

		}else{count = 1;}
		
		prev = cur;
	}
	return largest;
}
