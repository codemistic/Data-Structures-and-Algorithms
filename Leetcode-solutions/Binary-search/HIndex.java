public class HIndex {
    public static void main(String[] args) {
        int[] citations = {1,2,100};
        System.out.println(hIndex(citations));
    }

    static int hIndex(int[] citations) {
        int s = 0;
        int e = citations.length-1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(citations[m] >= (citations.length - m) ){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return citations.length - s;
    }

}
