/**
The array a(1..n) contains arbitrary integers. Write a function reduce(a,n) that reduces
the array a(1..n) by eliminating from it all values that are equal to three largest different
integers. For example, if a=(9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9) then three largest different
integers are 6,7,9 and after reduction the reduced array will be a=(1,1,1,2,3,3,5), n=7. The
solution should have time complexity O(n).
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * reduce(int arr[], int size);
void printarr(int arr[], int size);

int main()
{
	//create demo array for testing
	int demo[16] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
	int * ptr = demo;

	printf("The demo array is: ");
	printarr(ptr, 16);

	ptr = reduce(ptr, 16);
	printf("The reduced array is: ");
	printarr(ptr, 7);

	return 0;
}

int * reduce(int arr[], int size)
{
	//find the 3 largest integers
	int first = 0, second = 0, third = 0, count = 0, i;
	int * num;
	for(i = 0; i < size; i++)
	{
		if(arr[i] >= first)
		{
			if(arr[i] > first)
			{
				third = second;
				second = first;
				first = arr[i];
			}
		}
		else if(arr[i] >= second)
		{
			if(arr[i] > second)
			{
				third = second;
				second = arr[i];
			}
		}
		else if(arr[i] >= third)
		{
			if(arr[i] > third){third = arr[i];}
		}
	}

	//copy array excluding the 3 largest int
	num = (int*)malloc(size * sizeof(int));
	if(num == NULL)
   	{
    	fprintf(stderr, "Error: unable to allocate required memory\n");
  	}
  	else
	{
		for(i = 0; i < size; i++)
		{
			if((arr[i] != first) && (arr[i] != second) && (arr[i] != third))
			{
				*(num + count) = arr[i];
				count++;
			}

		}
	}

	//trim excess memory space
	num = realloc(num, count * sizeof(int));
	if(num == NULL)
	{
		fprintf(stderr, "Error - unable to allocate required memory\n");
	}

	return num;
}

//function to print an array of int
void printarr(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
