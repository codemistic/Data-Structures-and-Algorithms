public class FirstbadVersion {
    public static void main(String[] args) {
        int n = 1;
        System.out.println( firstBadVersion2(n));
    }

    static int firstBadVersion(int n) {
        int s = 1;
        int e = n;

        while(s <= e){
            int m = s + (e-s)/2;

            if( isBadVersion(m) ){
                e = m-1;
            } else{
                s = m+1;
            }
        }

        return s;
    }

    static int firstBadVersion2(int n){
        int s = 1;
        int e = n;

        while(s < e){
             int m = s + (e-s)/2;

             if(isBadVersion(m)){
                 e = m;
             } else{
                 s = m+1;
             }
        }
        return isBadVersion(s) ? s : s+1;
    }

    static boolean isBadVersion(int n){
        return 1 == n;
    }
}
