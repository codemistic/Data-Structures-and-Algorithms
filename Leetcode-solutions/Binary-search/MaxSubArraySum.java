public class MaxSubArraySum {
    public static void main(String[] args) {
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(maxSubArray(nums));
    }

    static int maxSubArray(int[] nums) {
        //kadane's algorithm
        int max = nums[0];
        int curr = 0;

        for (int num : nums) {

            curr += num;

            if(max < curr){
                max = curr;
            }

            if(curr < 0){
                curr = 0;
            }
        }

        return max;
    }
}
