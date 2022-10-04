class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        set<vector<int>> st;
        vector<int> t = nums;
        do
        {
            next_permutation(t.begin(), t.end());
            st.insert(t);
        } while (t != nums);
        vector<vector<int>> res;
        for (auto it: st)
            res.push_back(it);
        return res;
    }
};