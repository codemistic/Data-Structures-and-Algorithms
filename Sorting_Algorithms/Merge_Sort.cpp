#include <bits/stdc++.h>
using namespace std;
void mergeSort(int arr[], int n);
void Merge(int left[], int right[], int arr[], int x, int y,int n);
void printArray(int arr[], int n);
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, n);
    printArray(arr,n);
}
void mergeSort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    Merge(left, right, arr, mid, n - mid,n);
}
void Merge(int left[], int right[], int arr[], int x, int y,int n)
{
    int i = 0, j = 0, k = 0;
    while (i < x && j < y)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < x)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < y)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}