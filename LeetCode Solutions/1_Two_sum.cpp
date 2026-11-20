class Solution{
  public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int>mp;  //<value,index>
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){   //if number is found in map
                res.push_back(mp[nums[i]]);
                res.push_back(i);
                break;
            }
            mp[target-nums[i]]=i;
        }
        return res;
    }
};
