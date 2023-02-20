//William Zhang 251215208 CS2211 Assginment 3 part 251215208
//The function of this program is to take in an array and perform different commands on it

#include <stdio.h>
#include <limits.h>
#include <math.h>

void printIndexArray(int* arr, int numLength) {
	int i;
	printf("\nPart 1:\n ");
	printf("\tYour array is: ");
	//loop through the array and print out each value and corresponding index
	for(i = 0; i < numLength - 1; i++) {
	    printf("[%d] = %d, ", i, arr[i]);
	}
	//print the final array and index
	printf("[%d] = %d", i, arr[i]);
	printf("\n");
}

void largestValue(int* arr, int numLength) {
    //initialize variables
	int i, index = 0;
	//set largest to be the MIN of the array 
    int largest = INT_MIN;
	printf("\nPart 2:\n ");
	//if the current value is larger than the current largest value, replace it with the new value
	for(i = 0; i < numLength; i++){
		if(arr[i] > largest) {
		    largest = arr[i];
		}
	}
	printf("\tThe largest value in your array is: %d", largest);
	printf("\n");
}

void reverse(int* arr, int numLength) {
	int i;
	printf("\nPart 3:\n ");
	printf("\tYour array in reverse is: ");
	//loop through the array and print it out starting from the back to the front
	for(i = numLength - 1; i >= 0; i--){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}

void arraySum(int* arr, int numLength) {
    //initialize variables
	int i;
	int sum = 0;
	printf("\nPart 4:\n ");
	//loop through array and add each value, then print out the total
	for(i = numLength - 1; i >= 0; i--){
		sum = sum + arr[i];
	}
	printf("\tThe sum of all values in your array is: %d", sum);
	printf("\n");
}

void arraySorted(int* arr, int numLength) {
    //create a duplicate array
	int duplicateHolder[numLength];
	//initialize variables
	int i, j;
	//loop through array 
	for(int i = 0; i < numLength; i++) {
	    duplicateHolder[i] = arr[i];
	}
	//use sorting algo to sort the array (basic bubble sort)
	for(i = 0; i < numLength; i++) {
		for(j = 0; j < numLength - i - 1; j++) {
		    //switch array positions
			if(duplicateHolder[j] < duplicateHolder[j + 1]) {
				int temp = duplicateHolder[j];
				duplicateHolder[j] = duplicateHolder[j + 1];
				duplicateHolder[j + 1] = temp;
			}
		}
	}
	printf("\nPart 5:\n ");
	printf("\tYour array in sorted order is: ");
	//loop through array and print sorted one 
	for(i = 0; i < numLength; i++){
		printf("%d ", duplicateHolder[i]);
	}
	printf("\n");
}

void swapFirstLast(int* arr, int numLength) {
    printf("\nPart 6:\n ");
    printf("\tYour array with first and last element switched is: ");
    //set temp value as first value in array
	int temp = arr[0];
	//set current array value as final value
	arr[0] = arr[numLength - 1];
	//switch first and last value
	arr[numLength - 1] = temp;
		for(int i = 0; i < numLength; i++) {
		    printf("%d ", arr[i]);
	}
	printf("\n");
}

//main function must be at the bottom since functions must be declared before use
int main(void) {
    //initialize variables
    int numLength, i;
    printf ("Please enter the number of integers to process: ");
    scanf ("%d", &numLength);
    //this is because without it, it would just give the size of the pointer and not the actual size of the array
    int arr[numLength];
    printf ("\tThere is enough room in your array for %d integers ", numLength);
    printf ("(%d bytes)\n", (int) sizeof(arr));
    printf ("Please enter your integers separted by spaces: \n");
    //loop through the array 
    for (i = 0; i < numLength; i++) {
        scanf ("%d", &arr[i]);
    }
    //print out the results from the functions
    printIndexArray(arr, numLength);
    largestValue(arr, numLength);
    reverse(arr, numLength);
    arraySum(arr, numLength);
    arraySorted(arr, numLength);
    swapFirstLast(arr, numLength);
    
    return 0;
}