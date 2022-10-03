import java.util.* ;
public class Reverse {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in) ;
        System.out.println("Enter size of the array") ;
        int n = in.nextInt() ;
        int a[] = new int[n] ;
        System.out.println("Enter the elements ") ;
        for(int i=0 ; i<n ; i++){
            a[i] = in.nextInt() ;
        }
        int lptr=0 , rptr=n-1 ;
        while(lptr<rptr){
            int temp = a[lptr] ;
            a[lptr] = a[rptr] ;
            a[rptr] = temp ;
            lptr++ ;
            rptr-- ;
        }
        System.out.println("Revered array :") ;
        for(int el : a){
            System.out.print(el+" ");
        }
    }
}
