class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        // declarations
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        vector<int> ans;
        map<int, int> fz;

        // store frequency
        for (auto i : nums)
            fz[i]++;

        // reverse traverse map and store in bucket
        for (auto i = fz.rbegin(); i != fz.rend(); ++i)
            bucket[i->second].push_back(i->first);

        // main logic
        for (int i = 1; i <= n && ans.size() <= n; i++)
        {
            int j = 0;
            while (j < bucket[i].size())
            {
                for (int k = 0; k < i; k++)
                {
                    ans.push_back(bucket[i][j]);
                    if (ans.size() == n)
                        break;
                }
                j++;
            }
        }
        return ans;
    }
};