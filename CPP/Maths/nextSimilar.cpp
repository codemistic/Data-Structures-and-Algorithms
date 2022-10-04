// Given a number A in a form of string.

// You have to find the smallest number that has same set of digits as A and is greater than A.

// If A is the greatest possible number with its set of digits, then return -1.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    int n = A.length();
    int i;
    for (i = n - 1; i > 0; i--)
    {
        if (A[i] > A[i - 1])
            break;
    }
    if (i == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int x = A[i - 1], smallest = i;
    for (int j = i + 1; j < n; j++)
    {
        if (A[j] > x && A[j] < A[smallest])
            smallest = j;
    }

    swap(A[smallest], A[i - 1]);
    sort(A.begin() + i, A.end());
    cout << A << endl;
    
    return 0;
}