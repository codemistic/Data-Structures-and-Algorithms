public class SearchInsertPosition {
    public static void main(String[] args) {
        int[] arr = {-9, -6, -1, 5, 11, 13, 16, 20};
        int target = 10;
        System.out.println( binarySearch2(arr, target) );
    }

    static int binarySearch1(int[] arr, int target) {  //or the name can be ceil the smallest number >= target (if target is present it will be the smallest num which is >= itself and if it's not present then it would be where ? the place where the smallest number after it is present this is nothing but ceiling
        int s = 0;
        int e = arr.length-1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(arr[m] <= target) {
                s = m+1;
            } else{
                e = m -1;
            }
        }
        return s;   //s will be always point to the smallest x and e will always be point to the greatest x
        //for ex in this case we are finding the SMALLEST number that is >= to the target
    }

    static int binarySearch2(int[] arr, int target) {
        int s = 0;
        int e = arr.length-1;

        while (s < e){
            int m = s + (e-s)/2;

            if( isGreaterEqual(arr[m], target) ) {
                e = m;
            } else{
                s = m+1;
            }
        }
        return isGreaterEqual(arr[s], target) ? s : s + 1;  //in the end s and e will point to the same value that is our answer and here the condition will break we can return s or e anything but s jada lgta  kyunki s se smallest
        //ye check ye h ki maanlo ek aisa num jo arr ke max se bhi bda ho jse 98 to iska ceil kya higa ya fir agr ye hota to kahan hita jb ye run hoga tb last mai s or e ek ko hi point krega or vo higa last index kyunki humne search space hi ye bnaya hua h to isliye ye return krne se pehle check ki ye bhi h ya nhi, agr h to thik nhi to s +1 hi h ans
    }

    static boolean isGreaterEqual(int num, int target) {
        return num >= target;
    }

}
