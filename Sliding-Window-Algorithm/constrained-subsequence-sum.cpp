// Sliding Window Maximum
// Jump game 6
class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size(), res = nums[0];
        int dp[n + 1];
        dp[0] = nums[0];

        deque<int> q;
        q.push_back(dp[0]);

        for (int i = 1; i < n; ++i)
        {
            if (i > k && q.front() == dp[i - k - 1])
                q.pop_front();

            while (q.size() && q.back() < 0)
                q.pop_back();

            dp[i] = q.size() ? q.front() + nums[i] : nums[i];

            while (q.size() && q.back() < dp[i])
                q.pop_back();

            q.push_back(dp[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};