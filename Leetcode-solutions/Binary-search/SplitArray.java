//question = https://leetcode.com/problems/split-array-largest-sum/

public class SplitArray {
    public static void main(String[] args) {
        int[] nums = {7,2,5,10,8};
        int m = 2;
        System.out.println(splitArray(nums, m));
    }

    static int splitArray(int[] nums, int m) {
        int s = nums[0];
        int e = 0;

        for(int num : nums){
            s = num > s ? num : s;
            e += num;
        }

        while(s < e){
            int mid = s + (e-s)/2;

            if( isPotentialLargestSum(mid, nums, m) ){
                e = mid;
            } else{
                s = mid + 1;
            }
        }
        return s; //e is also ok as they both are pointing to the same element ie ans
    }

    static boolean isPotentialLargestSum(int estimatedLargest, int[] nums, int piecesAsked) {
        int pieces = 1;
        int sum = 0;

        for(int num : nums){
            if(sum + num > estimatedLargest){
                sum = 0;
                pieces++;
            }
            sum += num;
        }

        return pieces <= piecesAsked;
    }
}
