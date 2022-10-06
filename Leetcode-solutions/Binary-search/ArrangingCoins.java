//question - https://leetcode.com/problems/arranging-coins/

public class ArrangingCoins {
    public static void main(String[] args) {
        int n = 1;
        System.out.println(arrangeCoins2(n));
    }

    static int arrangeCoins(int n) {
        long s = 1;
        long e = n;

        while(s <= e){
            long m = s + (e-s)/2;
            long coinsNeeded = (m * (m+1)) /2;

             if(coinsNeeded <= n){
                 s = m+1;
             } else{
                  e= m-1;
             }
        }
        return (int)e;
    }

    static int arrangeCoins2(int n){
        long s = 1;
        long e = n;

        while(s < e){
            long m = s + (e-s)/2;
            long coinsNeeded = (m * (m+1)) /2;

            if(coinsNeeded <= n){
                s = m+1;
            } else{
                e = m;
            }
        }
        return (s * (s+1)) /2 <= n ? (int)s : (int)s-1;
    }

}
