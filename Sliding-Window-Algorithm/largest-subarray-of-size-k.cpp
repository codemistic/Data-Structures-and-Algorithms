#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for positive numbers only, for negative use map method
int lengthLargestSubarraySumK(vector<int> A, int k)
{
    int n = A.size(), i = 0, j = 0, maxLength = 0, sum = 0;

    while (j < n)
    {
        sum += A[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= A[i];
                i++;
            }
            if (sum == k)
                maxLength = max(maxLength, j - i + 1);
            j++;
        }
    }
    return maxLength;
}

int main()
{
    vector<int> A = {2, 1, 5};
    int k = 5;
    cout << lengthLargestSubarraySumK(A, k);
    return 0;
}