class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(auto it:nums)
        {
            if(it%2==0) even.push_back(it);
            else odd.push_back(it);
        }
        vector<int> v;
        for(auto it:even)
        {
            v.push_back(it);
        }
        for(auto it:odd)
        {
            v.push_back(it);
        }
        return v;
        
    }
};