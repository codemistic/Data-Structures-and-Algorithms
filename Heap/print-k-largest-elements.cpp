#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 0; i < n; i++)
        {
            minH.push(arr[i]);
            if (minH.size() > k)
                minH.pop();
        }
        vector<int> ans;
        while (minH.size() > 0)
        {
            ans.push_back(minH.top());
            minH.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};