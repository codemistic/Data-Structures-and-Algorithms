import java.util.ArrayList;
import java.util.Arrays;

public class IntersectionOfTwoArrays {
    public static void main(String[] args) {

    }

    static int[] intersection(int[] nums1, int[] nums2) {
        if(nums1.length > nums2.length){
            return intersection(nums2, nums1);
        }
        ArrayList<Integer> list = new ArrayList<>();
        Arrays.sort(nums1);

        for(int num : nums2){

            if(bS(nums1, num)){
                if(!list.contains(num)){
                    list.add(num);
                }
            }
        }

        int[] ans = new int[list.size()];

        for(int i = 0 ; i < list.size() ; i++){
            ans[i] = list.get(i);
        }
        return ans;
    }

    static boolean bS(int[] arr, int target){
        int s = 0;
        int e = arr.length-1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(arr[m] == target){
                return true;
            }
            if(arr[m] < target){
                s = m+1;
            } else{
                e = m-1;
            }
        }
        return false;
    }

}
