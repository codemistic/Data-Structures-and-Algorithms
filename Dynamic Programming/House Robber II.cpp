class Solution {
public:
   int Shivam(vector<int>&nums){
        int n = nums.size();
        
        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i = 1; i < n; i++){
            int peek = nums[i];
            if(i > 1) peek += prev2;
            int npeek = 0+prev1;
            int cur = max(peek,npeek);
            prev2 = prev1;
            prev1=cur;
        }
        return prev1;
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return nums[0];
        }
        
        vector<int>tmp1,tmp2;
        
        for(int i = 0; i < n; i++){
            if(i!=0){
                tmp1.push_back(nums[i]);
            }
            if(i!=n-1){
                tmp2.push_back(nums[i]);
            }
        }
        return max(Shivam(tmp1),Shivam(tmp2));
    }
};
