
//question = https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

public class MinInRotatedArray {
    public static void main(String[] args) {
        int[] nums = {3,4,5,1,2};
        System.out.println(findMin(nums));
    }

    static int findMin(int[] nums) {
        int s = 0;
        int e = nums.length-1;

        while(s < e){
            int m = s + (e-s)/2;

            if( nums[m] < nums[e]){
                e = m;
            } else{
                s = m+1;
            }
        }
        return nums[s];
    }
}
