import java.util.ArrayList;
import java.util.List;

public class KClosestElement {
    public static void main(String[] args) {
        int[] arr = {1,1,2,2,2,2,2,3,3};
        System.out.println( findClosestElements(arr, 3, 3) );
    }

    static List<Integer> findClosestElements(int[] arr, int k, int x) {
        int s = 0;
        int e = arr.length-k;

        while(s < e){
            int m = s + (e-s)/2;

            int indexJustAfterWindow = m+k;
            while(indexJustAfterWindow <= e && arr[m] == arr[indexJustAfterWindow] ){
                indexJustAfterWindow++;
            }

            if( Math.abs( arr[m] - x ) > Math.abs( x - arr[indexJustAfterWindow] ) ){
                s = m+1;
            } else{
                e = m;
            }
        }

        List<Integer> list = new ArrayList<>();
         for(int i = s; i < s +k ; i++){
             list.add( arr[i] );
         }
         return list;
    }
}
