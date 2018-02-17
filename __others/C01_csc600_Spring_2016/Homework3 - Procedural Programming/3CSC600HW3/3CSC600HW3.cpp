#include <iostream>

using namespace std;

void reduce(int theArray[], int n) {

    //initialize variables that will store the largest 3.
    int largest1 = 0, largest2 = 0, largest3 = 0;
    
    //collects the three largest numbers into variables.
    for (int i = 0; i < n; i++) 
    {
        /*replaces 1st largest variable if it is less than current element
        and shifts the 2nd and 3rd largest down*/
        if ((theArray[i] > largest1) && (theArray[i] != largest1)) 
        {
            largest3 = largest2;
            largest2 = largest1;
            largest1 = theArray[i];
        } 
        /*replaces 2nd largest variable if it is less than current element
        and shifts the 3rd largest down*/
        else if ((theArray[i] > largest2) && (theArray[i] != largest1)) 
            {
                largest3 = largest2;
                largest2 = theArray[i];
            } 
            //replaces 3rd largest variable if it is less than current element 
            else if ((theArray[i] > largest3) && (theArray[i] != largest2) && (theArray[i] != largest1)) 
                {
                    largest3 = theArray[i];
                }
    }
    
    /*increments through the array and sets anything greater than or equal
    to the 3rd largest to NULL*/
    int Index = 0;
    for (int i = 0; i < n; i++) {
        if (theArray[i] < largest3) {
            theArray[Index] = theArray[i];
            Index++;
        } else {
            theArray[Index] = NULL;
        }
    }
}

int main(void) {
    //initialize the sample array
    int theArray[] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
    int n = 16;
    
    //print out the sample array
    cout << "The initial Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << theArray[i] << " ";
    }
    cout << ", n = " << n << endl;
    
    //call function to remove three largest numbers from array
    reduce(theArray, n);
    cout << "The Reduced Array: " << endl;
    int i = 0;
    int newNCount=0;
    //prints out a redueced array
    while (theArray[i] != NULL) {
        cout << theArray[i] << " ";
        i++;
        newNCount++;
    }
    cout << ", n = " << newNCount << endl;
    return 0;
}
