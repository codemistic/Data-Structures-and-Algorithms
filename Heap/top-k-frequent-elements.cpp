// Hash Map + Heap [easy but time consuming]

// Hash Map + Bucket Sort [easy and cheap]
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &A, int k)
    {
        vector<int> ans;

        // declare and init map
        unordered_map<int, int> fz;
        for (int i : A)
            fz[i]++;

        // declare and init buckets
        vector<vector<int>> buckets(A.size() + 1);
        for (auto i : fz)
        {
            buckets[i.second].push_back(i.first);
        }

        // store answers
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; i--)
        {
            for (auto j : buckets[i])
            {
                ans.push_back(j);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};