#include <iostream>
#include <queue>
using namespace std;

void printSorted(int A[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < n; i++)
    {
        minH.push(A[i]);
        if (minH.size() > k)
        {
            cout << minH.top() << " ";
            minH.pop();
        }
    }
    while (minH.size() > 0)
    {
        cout << minH.top() << " ";
        minH.pop();
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        printSorted(A, n, k);
    }
    return 0;
}