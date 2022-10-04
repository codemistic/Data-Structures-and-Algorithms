public class PeakElement {
    public static void main(String[] args) {
        int[] nums = {1,2,3,1};
        System.out.println(findPeakElement(nums));
    }

    static int findPeakElement(int[] nums) {
        int s = 0;
        int e = nums.length-1;

        while(s < e){
            int m = s + (e-s)/2;

            if(nums[m] > nums[m+1]){
                e = m;
            } else{
                s = m+1;
            }
        }
        return s;
    }
}
