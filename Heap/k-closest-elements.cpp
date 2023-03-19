#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &A, int k, int x)
    {
        vector<int> ans(k);
        priority_queue<pair<int, int>> maxH;
        for (int i = 0; i < A.size(); i++)
        {
            maxH.push(make_pair(abs(A[i] - x), A[i]));
            if (maxH.size() > k)
                maxH.pop();
        }
        int j = 0;
        while (maxH.size() > 0)
        {
            pair<int, int> A = maxH.top();
            ans[j++] = A.second;
            maxH.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};