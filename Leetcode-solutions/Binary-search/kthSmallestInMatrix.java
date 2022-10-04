public class kthSmallestInMatrix {
    public static void main(String[] args) {
        int[][] matrix = {
                {1,5,9},
                {10,11,13},
                {12,13,15},
        };
        int k = 8;
        System.out.println(kthSmallest(matrix, k));
    }

    static int kthSmallest(int[][] matrix, int k) {
        int s = matrix[0][0];
        int e = matrix[ matrix.length-1 ][ matrix[0].length-1 ];  //wow

        while(s < e){
            int m = s + (e-s)/2;

            if( isPotentialK(matrix, m, k) ){
                e = m;
            } else {
                s = m+1;
            }
        }
        return s;  //or e as they are pointing to the same elm
    }

    static boolean isPotentialK(int[][] matrix, int m, int k) {
        int count = 0;

        int r = 0;
        int c = matrix[0].length-1;

        while(r < matrix.length && c >= 0){
            if(matrix[r][c] <= m){
                count += c+1;
                r++;
            } else{
                c--;
            }
        }
        return count >= k;
    }
}
