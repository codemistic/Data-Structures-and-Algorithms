public class ValidPerfectSquare {
    public static void main(String[] args) {
        int num = 1;
        System.out.println(isPerfectSquare(num));
    }

    static boolean isPerfectSquare(int num) {
        long s = 1;
        long e = (num/2) +1;

        while(s <= e){
            long m = s + (e-s)/2;

            if(m*m == num){
                return true;
            }
            if(m *m < num){
                s = m + 1;
            } else{
                e = m-1;
            }
        }
        return false;
    }
}
