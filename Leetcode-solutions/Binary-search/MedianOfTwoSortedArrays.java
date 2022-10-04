public class MedianOfTwoSortedArrays {
    public static void main(String[] args) {

    }

    static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums2.length < nums1.length){
            return findMedianSortedArrays(nums2, nums1);
        }

        int s = 0;
        int e = nums1.length;

        while(s <= e){
            int cut1 = s + (e-s)/2;
            int cut2 = (nums1.length + nums2.length) /2 - cut1;

            int l1 = cut1 <= 0 ? Integer.MIN_VALUE : nums1[cut1 - 1];
            int l2 = cut2 <= 0 ? Integer.MIN_VALUE : nums2[cut2 - 1];

            int r1 = cut1 >= nums1.length ? Integer.MAX_VALUE : nums1[cut1];
            int r2 = cut2 >= nums2.length ? Integer.MAX_VALUE : nums2[cut2];

            if( l1 > r2 ){
                e = cut1 - 1;
            } else if( l2 > r1 ){
                s = cut1 + 1;
            } else{
                return (nums1.length + nums2.length) % 2 == 0 ?
                        (float) ( Math.max(l1, l2) + Math.min(r1, r2) ) / 2 :
                        Math.min(r1, r2);
            }

        }
        return -1;
    }
}
