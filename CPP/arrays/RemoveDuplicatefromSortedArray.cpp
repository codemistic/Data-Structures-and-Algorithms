class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        vector<int> :: iterator it;

        for(it = nums.begin();it!=nums.end();it++)
        {
            int ele = *it;
            if(find(v.begin(),v.end(),ele)!=v.end())
            {
                nums.erase(it);
                it--;
            }
            else
                v.push_back(*it);

        }
        return nums.size();
    }
};