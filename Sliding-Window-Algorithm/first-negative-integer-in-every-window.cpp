#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> getFirstNegativeIntegers(vector<int> A, int n, int k)
{
    vector<int> ans(n - k + 1);
    queue<int> negativeVals;
    int i = 0, j = 0, p = 0;
    while (j < n)
    { // we push all negative values to a queue
        if (A[j] < 0)
            negativeVals.push(A[j]);

        // if window size  == k
        if (j - i + 1 == k)
        {
            if (negativeVals.empty())
                ans[p++] = 0;
            else
                ans[p++] = negativeVals.front();
            if (A[i] == negativeVals.front())
                negativeVals.pop();
            i++;
            j++;
        }
        else // increase window size to make it k
            j++;
    }
    return ans;
}

void printArr(vector<int> A)
{
    for (auto i : A)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, k;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A[i] = x;
        }
        cin >> k;
        printArr(getFirstNegativeIntegers(A, n, k));
        T--;
    }
}