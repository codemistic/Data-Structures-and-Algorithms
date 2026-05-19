#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start - 1;
    for (int i = start; i <= end - 1; i++)
    {
        if (arr[i] < pivot)
        {
            pIndex++;
            swap(&arr[pIndex], &arr[i]);
        }
    }
    swap(&arr[pIndex + 1], &arr[end]);
    return pIndex + 1;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
}