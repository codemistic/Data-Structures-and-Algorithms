class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        vector<int> v(st.begin(), st.end());
        // predicate nums[x]>=nums[0] /// tttttffffff aim--> finding first f
        int low = 0, high = v.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (v[mid] >= v[0])
                low = mid + 1;
            else
                high = mid;
        }
        // turn low;
        return min(v[0], v[low]);
    }
};