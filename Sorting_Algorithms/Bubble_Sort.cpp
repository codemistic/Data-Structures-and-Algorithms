#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n);
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
    bubbleSort(arr, n);
}
void bubbleSort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
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