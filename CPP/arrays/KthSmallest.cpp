#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// It searches for x in arr[], and partitions the array around x
int partition(int arr[], int l, int r, int x) {
   // Search for x in arr[] and move it to end
   int i;
   for (i = l; i < r; i++)
       if (arr[i] == x)
           break;
   swap(arr[i], arr[r]);

   // Standard partition algorithm
   i = l;
   for (int j = l; j <= r - 1; j++) {
       if (arr[j] <= x) {
           swap(arr[i], arr[j]);
           i++;
       }
   }
   swap(arr[i], arr[r]);
   return i;
}

// A simple function to find median of arr[]
int findMedian(int arr[], int n) {
   sort(arr, arr + n);
   return arr[n / 2];
}

// Returns kth smallest element in arr[] in worst case linear time
int kthSmallest(int arr[], int l, int r, int k) {
   // If k is smaller than number of elements in array
   if (k > 0 && k <= r - l + 1) {
       int n = r - l + 1;

       // Divide arr[] in groups of size 5, calculate median
       // of every group and store it in median[] array
       int i, median[(n + 4) / 5];
       for (i = 0; i < n / 5; i++)
           median[i] = findMedian(arr + l + i * 5, 5);
       // For the last group
       if (i * 5 < n) {
           median[i] = findMedian(arr + l + i * 5, n % 5);
           i++;
       }

       // Find median of all medians using recursive call
       int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);

       // Partitioning the array around a random element and
       // get position of pivot element in sorted array
       int pos = partition(arr, l, r, medOfMed);

       // If position is same as k
       if (pos - l == k - 1)
           return arr[pos];
       // If position is more, recur for left
       if (pos - l > k - 1)
           return kthSmallest(arr, l, pos - 1, k);

       // Else recur for right subarray
       return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
   }

   // If k is more than number of elements in array
   return INT_MAX;
}

int main() {
   int size, k;
   cout << "Enter size of array: ";
   cin >> size;

   int arr[size];
   cout << "Enter into the array:\n";
   for (int i = 0; i < size; i++)
       cin >> arr[i];

   cout << "Enter value of k: ";
   cin >> k;
   cout << endl;

   if (k % 10 == 1)
       cout << k << "st smallest element is: " << kthSmallest(arr, 0, size - 1, k);
   else if (k % 10 == 2)
       cout << k << "nd smallest element is: " << kthSmallest(arr, 0, size - 1, k);
   else if (k % 10 == 3)
       cout << k << "rd smallest element is: " << kthSmallest(arr, 0, size - 1, k);
   else
       cout << k << "th smallest element is: " << kthSmallest(arr, 0, size - 1, k);

   return 0;
}
