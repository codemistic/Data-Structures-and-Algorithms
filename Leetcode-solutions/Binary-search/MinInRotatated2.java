// question = https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

public class MinInRotatated2 {
    public static void main(String[] args) {
        int[] nums = {2,2,0,1};
        System.out.println(findMin(nums));
    }

    static int findMin(int[] nums) {
        int s = 0 ;
        int e = nums.length-1;

        while (s < e) {

            while(s < e && nums[s] == nums[s+1]){
                s++;
            }
            while(s < e && nums[e] == nums[e-1]){
                e--;
            }

            if(s == e){
                return nums[s];
            }

            int m = s + (e-s) /2;
            if(nums[e] > nums[m]){
                e = m;
            } else{
                s = m+1;
            }

        }
        return nums[s];
    }
}
