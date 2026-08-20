package Binary_On_1DArray;

public class SearchInsertPosition {
    
    public int searchInsert(int[] nums, int target) {
        int low=0;
        int high=nums.length-1;
        int mid;
        while(low<=high)
        {
            mid=(low)+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if (nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
}