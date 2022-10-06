//question = https://leetcode.com/problems/search-in-rotated-sorted-array/

public class RotatedBS {
    public static void main(String[] args) {
        int[] nums = {4,5,6,7,0,1,2};
        int target = 0;
        System.out.println(search(nums, target));
    }

    static int search(int[] nums, int target) {
        int s = 0;
        int e = nums.length-1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(nums[m] == target){
                return m;
            }

            if(nums[m] >= nums[s]){
                if(target < nums[m] && target >= nums[s]){
                    e = m-1;
                } else{
                    s = m+1;
                }
            } else{
                if(target > nums[m] && target <= nums[e]){
                    s = m+1;
                } else{
                    e = m-1;
                }
            }
        }
        return -1;
    }
}
