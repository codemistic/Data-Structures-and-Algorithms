#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for positive numbers only, for negative use map method
int smallestSubarray(vector<int> A, int k)
{
    int n = A.size(), i = 0, j = 0, minLength = INT_MAX, sum = 0;
    while (j < n)
    {
        sum += A[j];
        while (sum > k)
        {
            minLength = min(minLength, j - i + 1);
            sum -= A[i];
            i++;
        }
        j++;
    }
    return minLength;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A[i] = x;
        }
        cout << smallestSubarray(A, k) << "\n";
        T--;
    }
    return 0;
}