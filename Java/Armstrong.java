/* Armstrong number is a three digit number whose sum of cube of each digit is equal to the number
* Example 153 = 1^3 + 5^3 + 3^3 = 153 */
public class Armstrong {
    static boolean Arms(int n){ 
        int org=n;
        int ans = 0;
        while(n>0){
            int rem=n%10;
            
            ans+=rem*rem*rem;
            n/=10;
        }
        return org==ans; 

    }
    public static void main(String[] args) {
        
        for (int i=100;i<1000;i++){
            if (Arms(i)){
                System.out.print(i+" ");
            }
        }
    }
}
