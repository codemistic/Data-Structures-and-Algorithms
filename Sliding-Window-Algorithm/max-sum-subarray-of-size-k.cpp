#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumSumSubarray(int K, vector<int> &a, int N)
    {
        int maxSum = INT_MIN, sum = 0, i = 0, j = 0;
        while (j < N)
        {
            sum += a[j];
            if (j - i + 1 == K)
            {
                maxSum = max(maxSum, sum);
                sum -= a[i];
                i++;
                j++;
            }
            else
                j++;
        }
        return maxSum;
    }
};