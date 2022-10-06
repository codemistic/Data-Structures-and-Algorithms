#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int> A, int n, int k)
{
    int i = 0, j = 0, outOfPlace = 0, minSwaps = INT_MAX;
    int windowSize = 0;
    if (n <= 1)
        return 0;

    for (int t = 0; t < n; t++)
        if (A[t] <= k)
            windowSize++;

    if (windowSize == 0)
        return 0;

    while (j < n)
    {
        // calculations
        if (A[j] > k)
            outOfPlace++;

        if (j - i + 1 < windowSize)
            j++;
        else if (j - i + 1 == windowSize)
        {
            // get ans
            minSwaps = min(minSwaps, outOfPlace);

            // slide
            if (A[i] > k)
                outOfPlace--;
            i++;
            j++;
        }
    }
    return minSwaps;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, k;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        cin >> k;
        cout << minSwaps(A, n, k) << "\n";
        T--;
    }
}