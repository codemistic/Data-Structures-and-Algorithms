public class Sqrt {
    public static void main(String[] args) {
        int n = 8;
        System.out.println(sqrt2(n));
    }

    static int sqrt(int n){
        long s = 1;
        long e = n;

        while(s <= e){
            long m = s + (e-s)/2;

            if(m * m <= n){
                s = m +1;
            } else{
                e = m -1;
            }
        }
        return (int)e;  //e will always point to the greatest value satisfying the condition in this s <= e wala case doosre tarike se abhi dekhte h
    }

    static int sqrt2(int n){
        long s = 1;
        long e = n;

        while(s < e){
            long m = s + (e-s)/2;

            if(m * m <= n){
                s = m+1;
            } else{
                e = m;
            }
        }
        return s*s <= n ? (int)s: (int)s-1;
        //idhr s-1 hoti h vo max value jo staisfy kregi condition ko lekin maano 1 ka sqrt to s or e dono hi 1 ko point krenge to is case mai loop run hi nhi hoga to kya krna h ki s-1 se pehle s ko dekhna h or agr ye satisfy krta h to yu hi bta s bda ya s-1 ? s hi na to bss use ho return nhi to simple s-1.
    }


}
