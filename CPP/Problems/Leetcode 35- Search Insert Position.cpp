class Solution
{
public:

    int position(vector<int>&nums,int begin,int end,int target)
    {
      int i=begin;
        int j=end;
        int ans1;
        while(j>=i)
        {
            int mid1=(i+j)/2;
            if(nums[mid1]==target)
                return mid1;
           
            if(nums[mid1]>target)
                j=mid1-1;
            else if(nums[mid1]<target)
                i=mid1+1;
        }
        return i;
        
            
    }
  int searchInsert(vector<int> &nums, int target)
  {
    int begin = 0;
    int end = nums.size() - 1;
    int ans = position(nums,begin,end,target);
    
   
    return ans;
  }
};
