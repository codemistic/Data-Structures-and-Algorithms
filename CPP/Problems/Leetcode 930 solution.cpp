class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0,s=0;
        for(auto x:nums)
        {
            s+=x;
            if(m.find(s-goal)!=m.end())
                ans+=m[s-goal];
            m[s]++;
        }
        return ans;
    }
};
