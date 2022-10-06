//question = https://leetcode.com/problems/peak-index-in-a-mountain-array/

public class PeakIndex {
    public static void main(String[] args) {
        int[] arr = {3,4,5,1};
        System.out.println(peakIndexInMountainArray(arr));
    }

    static int peakIndexInMountainArray(int[] arr) {
        int s = 0;
        int e = arr.length-1;

        while (s < e){
            int m = s + (e-s)/2;

            if(arr[m] > arr[m+1]){
                e = m;
            } else{
                s = m+1;
            }
        }
        return s;
    }
}
