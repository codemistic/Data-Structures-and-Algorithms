 import java.util.Arrays;

public class BinaraySearch {

    public static void main(String[] args) {
        int[] arr = {5,4,3,2,1};
        int target = 6;

        oderAgonosticBS(arr,6);
    }
   
   
    static int oderAgonosticBS(int [] arr , int target)
    {
        int start = 0;
        int end = arr.length - 1;

        boolean isAsc = arr[start] < arr[end];
        /*
        boolean isAsc ;
        if(= arr[start] < arr[end] )
        {
        isAsc = true;
        }isAsc = false;
       */

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == arr[mid]) return mid;

            if(isAsc)
            {
                if (target <  arr[mid])
                   end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (target >  arr[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return start ;
    }
}
