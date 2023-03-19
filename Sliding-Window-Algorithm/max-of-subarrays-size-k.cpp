#include <vector>
#include <deque>
using namespace std;

// returns vector containing max elements of all subarrays of size k

vector<int> max_of_subarrays(int *A, int n, int k)
{
    vector<int> ans;
    if (k > n)
    {
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
            if (A[i] > max)
                max = A[i];
        ans.push_back(max);
        return ans;
    }
    deque<int> windowVals;
    int i = 0, j = 0;
    while (j < n)
    {
        // calculations
        while (!windowVals.empty() && A[j] > windowVals.back())
            windowVals.pop_back();

        windowVals.push_back(A[j]);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            // get ans
            ans.push_back(windowVals.front());

            // slide
            if (A[i] == windowVals.front())
                windowVals.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}
