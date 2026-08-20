package Binary_On_1DArray;
class FirstAndLastPositionOfElementInsSortedArray {
    public int[] searchRange(int[] nums, int target) {
        int low=0;
        int high=nums.length-1;
        int mid;
        int index=-1;
        while(low<=high)
        {
          mid=low+(high-low)/2;
          if(nums[mid]==target)
          {
               index=mid;
               break;
          }
          if(nums[mid]>target)
          {
            high=mid-1;
          }
          else
          {
            low=mid+1;
          }
        }
        if(index==-1)
        {
            return new int[]{-1,-1};
        }
        
        int first=index;
        int last=index;
        while(first>0 && nums[first-1]==target)
        {
            first--;
        }
        while(last<nums.length-1 && nums[last+1]==target)
        {
            last++;
        }
        return new int[]{first,last};
    }
}