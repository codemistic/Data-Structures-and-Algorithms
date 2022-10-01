class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
       //number should be always between 1 to n
       for(int i=0;i<n;i++){
           if(nums[i]<=0 or nums[i]>n)
               nums[i]=n+1;
       }
        
       //
       for(int i=0;i<n;i++){
           if(abs(nums[i])<=n){
               int index=abs(nums[i])-1;
               nums[index]=-abs(nums[index]);
           }
       }
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};
