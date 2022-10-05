
// Let's assume that the elements of the array are linearly distributed.

// General equation of line : y = m*x + c.
// y is the value in the array and x is its index.

// Now putting value of lo,hi and x in the equation
// arr[hi] = m*hi+c ----(1)
// arr[lo] = m*lo+c ----(2)
// x = m*pos + c     ----(3)

// m = (arr[hi] - arr[lo] )/ (hi - lo)

// subtracting eqxn (2) from (3)
// x - arr[lo] = m * (pos - lo)
// lo + (x - arr[lo])/m = pos
// pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])

/*************************************************/

// Algorithm
// The rest of the Interpolation algorithm is the same except for the above partition logic.
// Step1: In a loop, calculate the value of “pos” using the probe position formula.
// Step2: If it is a match, return the index of the item, and exit.
// Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise, calculate the same in the right sub-array.
// Step4: Repeat until a match is found or the sub-array reduces to zero.

// Below is the implementation of the algorithm.

/*************************************************/

#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x)
                return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;

        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
    }
    return -1;
}

// Driver Code
int main()
{
    // Array of items on which search will
    // be conducted.
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18; // Element to be searched
    int index = interpolationSearch(arr, n, x);

    // If element was found
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";
    return 0;
}