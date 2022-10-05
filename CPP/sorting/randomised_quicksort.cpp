#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// This function places all smaller
// to left of pivot and all greater
// elements to right of pivot
int partition(int arr[], int low, int high) {
   int pivot = arr[high];

   // Index of smaller element
   int i = (low - 1);

   for (int j = low; j <= high - 1; j++) {
       // If current element is smaller
       // than or equal to pivot
       if (arr[j] <= pivot) {

           // increment index of smaller element
           i++;
           swap(arr[i], arr[j]);
       }
   }
   swap(arr[i + 1], arr[high]);
   return (i + 1);
}

// Generates Random Pivot, swaps pivot with end element
int partition_r(int arr[], int low, int high) {
   // Generates random number
   srand(time(NULL));
   int random = low + rand() % (high - low);

   // Swap A[random] with A[high]
   swap(arr[random], arr[high]);

   return partition(arr, low, high);
}

// Quicksort method
void quickSort(int arr[], int low, int high) {
   if (low < high) {
       int pIndex = partition_r(arr, low, high);

       // Separately sort elements before partition and after partition
       quickSort(arr, low, pIndex - 1);
       quickSort(arr, pIndex + 1, high);
   }
}

int main() {
   int size;
   cout << "Enter size of array: ";
   cin >> size;
   int arr[size];
   cout << "Enter contents of array:\n";
   for (int i = 0; i < size; i++)
       cin >> arr[i];

   cout << "\nUnsorted array:\n[ ";
   for (int i = 0; i < size; i++)
       cout << arr[i] << " ";
   cout << "]\n";

   quickSort(arr, 0, size - 1);

   cout << "Sorted array:\n[ ";
   for (int i = 0; i < size; i++)
       cout << arr[i] << " ";
   cout << "]\n";

   return 0;
}
