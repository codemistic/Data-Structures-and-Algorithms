#include <iostream>  
using namespace std;  
/* function to heapify a subtree. Here 'i' is the   
index of root node in array a[], and 'n' is the size of heap. */   
void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  
/*Function to implement the heap sort*/  
void heapSort(int a[], int n)  
{  
  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  
/* function to print the array elements */  
void printArr(int a[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        cout<<a[i]<<" ";  
    }  
          
}  
int main()  
{  
    int a[] = {47, 9, 22, 42, 27, 25, 0};  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    heapSort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(a, n);  
    return 0;  
}  
