class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size(), curr = -1;
        vector<int> res(n - k + 1);
        deque<int> q;

        for (int i = 0; i < n; ++i)
        {
            if (i >= k && nums[i - k] == q.front())
                q.pop_front();

            while (q.size() && q.back() < nums[i])
                q.pop_back();

            q.push_back(nums[i]);

            if (i >= k - 1)
                res[++curr] = q.front();
        }

        return res;
    }
};