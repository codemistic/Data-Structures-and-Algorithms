// Problem link:https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            vector<int> check;
            int find=-(nums[i]);
            int l=i+1,r=n-1;
            while(r>l){
                int sum=(nums[l]+nums[r]);
                if(sum==find){ 
                    check.push_back(nums[i]);
                    check.push_back(nums[l]);
                    check.push_back(nums[r]);
                    st.insert(check);
                    if(check.size()==3){
                        check.clear();
                    }
                    l++;r--;
                }
                else if(sum>find){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        
        for(auto el:st){
        vector<int> check1;
            for(int i=0;i<el.size();i++){
                check1.push_back(el[i]);
            }
            ans.push_back(check1);
        }
        return ans;

    }
};