/******************************************************************************
 * Hasan Niftiyev
 * CSC 600 - Homework 2

Problem 5: Iteration Vs Recursion

Make a sorted integer array a[i]=i, i=0,…,n-1. Let bs(a,n,x) be a binary search
program that returns the index i of array a[0..n-1] where a[i]=x. Obviously,
bs(a,n,x)=x, and the binary search function can be tested using the loop
for(j=0; j<K; j++)
for(i=0; i<n; i++) if(bs(a,n,i) != i) cout << “\nERROR”;
Select the largest n your software can support and then K so that this loop with an
iterative version of bs runs 3 seconds or more. Then measure and compare this run time
and the run time of the loop that uses a recursive version of bs. Compare these run times
using maximum compiler optimization (release version) and the slowest version
(minimum optimization or the debug version). If you use a laptop, make measurements
using AC power, and then same measurements using only the battery. What conclusions
can you derive from these experiments? Who is faster? Why?

Impression: When I increased K and N values, the gap between speed of iterative function
and recursive function has increased drammatically. I used three levels of compiler 
optimization where ratio of these two types of function decreased. I was also surprised
that AC adapter has afected runtime time tremendously. It was the most powerful 
factor that slowed down the computer while computer battery was used during runtime.

 * ****************************************************************************/




#include <iostream>
#include <time.h>
#define N 10000
#define K 10000

using namespace std;

int binarySearchIteration(int* , int , int);
int binarySearchRecursion(int* , int , int , int);

int main (){

	int array[N];

	//time measurement referred from stackoverlow
	clock_t time_start, time_end;
    float run_time;

	for (int index = 0; index < N ; index++)
		array[index]=index;


	time_start = clock();
	// Already Given test case
	for(int j=0; j < K; j++)
		for(int i=0; i < N; i++) 
			if(binarySearchIteration(array,N,i) != i) 
				cout << "\nERROR" << "from Iteration" << endl;
			
	time_end = clock();

	run_time = ((float)time_end - (float)time_start);
    cout << "Run Time for Iteration: " << run_time << endl; 

    float IterativeRuntime = run_time;

    time_start = clock();
	// Already Given test case
	for(int j=0; j < K; j++)
		for(int i=0; i < N; i++) 
			if(binarySearchRecursion(array,0,N,i) != i) 
				cout << "\nERROR" << "from Recursion" << endl;
		
	time_end = clock();

	run_time = ((float)time_end - (float)time_start);
    cout << "Run Time for Recursion: " << run_time << endl;
    cout << "Iteration/Recursion ratio: " << IterativeRuntime/run_time << endl; 



	return 0;


}

// Iterative search by well known algorithm with three parameters
int binarySearchIteration(int* array, int size, int target){
	int begin = 0; int end = size-1;
	int mid = 0;
	while (begin <= end){
		mid = (begin + end)/2;
		if (array[mid] < target)
			begin = mid + 1;
		else if (array[mid] > target)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

// Binary search with recursion. Need to have 4 parameters ! to keep
// track of upper portion of array.
int binarySearchRecursion(int* array, int begin , int end, int target){
	
	if (begin <= end) {
       int mid = (begin +  end) / 2;  

       if (target == array[mid]) 

           return mid;   

       else if (target < array[mid]) 

           return binarySearchRecursion(array, begin, mid-1, target);

       else
           
           return binarySearchRecursion(array, mid+1, end, target);
   }
   return -(begin + 1);    

}



