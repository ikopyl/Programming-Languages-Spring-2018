#include <iostream>
using namespace std;

int maxlen(int* a,int n){
	int streak=1;
	int max=0;
	int i; 
	for(i=1;i<n;i++)//Iterating n times
	{
		if(a[i]==a[i-1]) //if it matches previous spot
			streak++; 	 //add to the streak
		else if(streak > max){//otherwise if streak is largest
			max=streak;	 //save it as mac
			streak=1;	 //reset streak for new number
		}else			 //if no match
			streak=1;	 //reset streak 	
	}
	return max;			//return max streak
	//This solution finds the max streak only iterating through 
	//the array once. cannot be more efficient
}
 
int main (){
	int a[] = {4,4,6,3,2,2,2,2,2,5,5,7,7,2,5};//Create Array
	//Call function and print result
	cout<<"longest streak is: "<< maxlen(a,15)<<endl;
	return 0;
}
