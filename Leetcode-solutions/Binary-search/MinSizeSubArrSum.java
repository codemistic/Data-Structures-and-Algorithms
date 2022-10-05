public class MinSizeSubArrSum {
    public static void main(String[] args) {
        int[] nums = {2,3,1,2,4,3};
        int target = 77;
        System.out.println(minSubArrLength(target, nums));
    }

    static int minSubArrLength(int target, int[] nums){
        int s = 1;
        int e = nums.length;

        while(s < e){
            int m = s + (e-s)/2;

            if( condition(nums, m, target) ){
                e = m;
            } else{
                s = m+1;
            }
        }

        return condition(nums, s, target) ? s : 0;
    }

    static boolean condition(int[] nums, int m, int target) {
        for(int i = 0 ; i <= nums.length - m ; i++){

            int sum = 0;
            for(int j = i ; j-i < m ; j++){
                sum += nums[j];
            }

            if(sum >= target){
                return true;
            }
        }
        return false;
    }


}
