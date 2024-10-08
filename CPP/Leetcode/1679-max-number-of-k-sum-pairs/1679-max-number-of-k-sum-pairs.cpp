class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for(auto it: nums)
        {
            int x = k - it;
            if(mp[x] > 0){cnt++; mp[x]--;}
            else mp[it]++;
        }
        return cnt;
    }
};