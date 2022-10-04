import java.util.Arrays;

public class FirstLastPos {
    public static void main(String[] args) {
        int[] nums = {5,7,7,8,8,10};
        int target = 8;
        int[] ans = firstLastPosition(nums, target);
        System.out.println( Arrays.toString(ans) );
    }

    static int[] firstLastPosition(int[] nums, int target){
        int[] ans = {-1, -1};

        ans[0] = serach(nums, target, true);
        if(ans[0] == -1){
            return ans;
        }
        ans[1] = serach(nums, target, false);
        return ans;
    }

    static int serach(int[] nums, int target, boolean findingFirst){
        int s = 0;
        int e = nums.length-1;
        int ans = -1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(nums[m] == target){
                ans = m;

                if( findingFirst ){
                    e = m-1;
                } else{
                    s = m+1;
                }
            } else if(nums[m] < target){
                s = m+1;
            } else{
                e = m-1;
            }
        }

        return ans;
    }
}
