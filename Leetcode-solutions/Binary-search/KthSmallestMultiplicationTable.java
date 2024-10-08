public class KthSmallestMultiplicationTable {
    public static void main(String[] args) {
        int m = 3;
        int n = 3;
        int k = 5;
        System.out.println(findKthNumber(m, n, k));
    }

    static int findKthNumber(int m, int n, int k) {
        int s = 1;
        int e = m * n;

        while(s < e){
            int mid = s + (e-s)/2;

            if( isPotentialK(mid, m, n, k) ){
                e = mid;
            } else{
                s = mid + 1;
            }
        }
        return s; // or e as they both are pointing to the same element
    }

    static boolean isPotentialK(int potential, int m, int n, int k) {
        int count = 0;
        for(int i = 1; i <= m ; i++){
            count += Math.min( (potential / i)  , n );    //sun ye isliye kyunki ye hr row simply table h 1 se m tk ka, ab mujhe nikalna h hr row mai se 5 ya kisi num se kitne chhote to ye simploe nikl jaega, kse aise ki maan tujhe nikalna h ki 5 se chhote kitne num h 2 ke table mai to nikaal ki 5 2 ke table mai kahan aata h ya uska floor nikaal to ab 5 nhi aata to floor ya fr agr decial mai aaega na 5/2 = 2.5 to point to ht hi jaega int mai to 2 or haan yhi to h 2 ke table mai 5 se chhote 2 num h thike to ab ye potential/i waali baat to smjh aa gyi pr ye min kyu n se, isliye kyunki soch 1 ke table mai 5 se chhote ya baraabar kitne h 5/1 = 5 pr que mai given table to 3 tk jaari hna to mai ye thodi likh skti ki is row mai jisme 3 elements h usme 5 se chhote 5 elements h ab smjh gyi to kya hoga ki agr jada honge to fr wo min 3 ko lega or agr km honge to fr to whi h ans. huh!!!
        }
        return count >= k;
    }


}
