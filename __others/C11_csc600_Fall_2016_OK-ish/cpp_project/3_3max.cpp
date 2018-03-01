#include <iostream>
using namespace std;

int main (){
	int a[] = {3,5,9,6,3,1,6,8,9,6,4,6,3,6,8};
	int n=15; 
	int i,j,k,max;
	for(int b=0;b<n;b++)
		cout<<a[b]<<" "; //Print original Arr
	cout<<endl;
	for(i=0;i<3;i++)
	{//Each iteration eliminates the largest value
		max=0;
		for(j=0;j<n;j++)
		{//iterate through array to find max
			if(a[j]>a[max])
				max=j; //Find max value
		}
		max=a[max];
		for(j=n-1;j>-1;j--)
		{//eliminate all instances of max
			if(a[j]==max){
				n--;//decrement arr size
				for(k=j;k<n;k++)
					a[k]=a[k+1];
			}
		}
		for(int b=0;b<n;b++)
			cout<<a[b]<<" ";//print shrunken array 
		cout<<endl;
		//While this function is O(n), it iterates through more than
		//n times, but is still in the category, it goes 
		//through n 3 times, eliminating the max each time
		//which takes more iterations to actually shrink the arr
	}
	return 0;
}
