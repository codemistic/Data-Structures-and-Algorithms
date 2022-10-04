// program to print pivot index of a rotated sorted array
#include<iostream>
using namespace std;

int pivotIndex (int arr[], int lo, int hi) {
    // base case
    if (lo == hi) {
        return lo;
    }
    int mid = lo + (hi - lo)/2;
    // recursive relation
    if (arr[mid] >= arr[0]) { // LINE-1
        return pivotIndex(arr, mid+1, hi);
    }
    else { // LINE-2
        return pivotIndex(arr, lo, mid);
    }
}

int main() {
	int array[5] = {8,10,17,1,3};
	cout<<"Pivot index is: "<<pivotIndex(array, 0, 4);
	return 0;
}
