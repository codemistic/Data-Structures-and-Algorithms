// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive( arr, n-1 );

	// Insert last element at its correct position
	// in sorted array.
	int last = arr[n-1];
	int j = n-2;

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		cout << arr[i] <<" ";
}

/* Driver program to test insertion sort */
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSortRecursive(arr, n);
	printArray(arr, n);

	return 0;
}
