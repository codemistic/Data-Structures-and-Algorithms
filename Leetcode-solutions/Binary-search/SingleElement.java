public class SingleElement {
    public static void main(String[] args) {
        int[] nums = {3,3,7,7,10,11,11};
        System.out.println(singleNonDuplicate(nums));
    }

    static int singleNonDuplicate(int[] nums) {
        int s = 0;
        int e = nums.length-1;

        while(s < e){
            int m = s + (e-s)/2;

            if( (m < e) && (nums[m] == nums[m +1]) ){

                if( (m -s) % 2 == 0 ){
                    s = m +2;
                } else{
                    e = m-1;
                }

            } else if( (s < m) && (nums[m] == nums[m-1]) ){

                if( (e-m) % 2 == 0 ){
                    e = m-2;
                } else{
                    s = m+1;
                }

            } else{
                return nums[m];
            }
        }
        return nums[s]; //or e
    }
}
