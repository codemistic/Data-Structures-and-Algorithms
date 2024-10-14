#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n);
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
    selectionSort(arr, n);
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] <= arr[i] && arr[j] <= arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            arr[i] ^= arr[min];
            arr[min] ^= arr[i];
            arr[i] ^= arr[min];
        }
    }
    printArray(arr, n);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}