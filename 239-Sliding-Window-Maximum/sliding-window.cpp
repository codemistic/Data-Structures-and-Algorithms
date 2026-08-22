class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      multiset<int>c;
      vector<int>ans;
      for(int i=0;i<nums.size();i++)
      {
          if(i>=k)
            c.erase(c.find(nums[i-k]));
        c.insert(nums[i]);
        if(i>=k-1)
            ans.push_back(*c.rbegin());
      }
      return ans;
    }
};