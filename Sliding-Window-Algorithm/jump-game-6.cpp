// O(n) Method
// Sliding Window Maximum
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];

        deque<int> q;
        q.push_back(dp[0]);

        for (int i = 1; i < n; ++i)
        {
            if (i > k && q.front() == dp[i - k - 1])
                q.pop_front();

            dp[i] = q.front() + nums[i];

            while (q.size() && q.back() < dp[i])
                q.pop_back();

            q.push_back(dp[i]);
        }

        return dp[n - 1];
    }
};

// O(nlogn) Priority_queue solution
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size(), res = INT_MIN, curr = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        pq.emplace(nums[0], 0);

        for (int i = 1; i < n; ++i)
        {
            while (pq.size() && pq.top().second < i - k)
                pq.pop();

            int curr = pq.top().first;

            if (i == n - 1)
                return curr + nums[n - 1];

            pq.emplace(curr + nums[i], i);
        }

        return nums[0];
    }
};

// O(nlogn) Method using multiset
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dp[n];
        multiset<int> st;
        dp[0] = nums[0];
        st.insert(dp[0]);

        for (int i = 1; i < n; ++i)
        {
            if (i > k)
                st.erase(st.lower_bound(dp[i - k - 1]));
            dp[i] = *st.rbegin() + nums[i];
            st.insert(dp[i]);
        }

        return dp[n - 1];
    }
};

// O(N^2) Method
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];

        for (int i = 1; i < n; ++i)
        {
            dp[i] = INT_MIN;
            for (int j = max(0, i - k); j < i; ++j)
            {
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += nums[i];
        }

        return dp[n - 1];
    }
};