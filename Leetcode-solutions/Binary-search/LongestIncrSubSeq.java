import java.util.ArrayList;

public class LongestIncrSubSeq {
    public static void main(String[] args) {
        int[] nums = {1,1,1,1,1,1};
        System.out.println(lengthOfLIS(nums));
    }

    static int lengthOfLIS(int[] nums) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(nums[0]);

        for(int i = 1 ; i < nums.length ; i++){

            if( list.get( list.size() -1 ) < nums[i] ){
                list.add(nums[i]);
            } else{
                int index = ceil(list, nums[i]);
                list.set(index, nums[i]);
            }

        }

        return list.size();
    }

    static int ceil(ArrayList<Integer> list, int target){
        int s = 0;
        int e = list.size() -1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(list.get(m) >= target){
                e = m-1;
            } else{
                s = m+1;
            }
        }
        return s;
    }

}
