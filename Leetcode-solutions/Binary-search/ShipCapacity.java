public class ShipCapacity {
    public static void main(String[] args) {
        int[] weights = {1,2,3,4,5,6,7,8,9,10};
        System.out.println( shipWithinDays(weights, 5));
    }

    static int shipWithinDays(int[] weights, int days) {
        int s = weights[0];
        int e = 0;

        for(int weight: weights){
            s = Math.max(s, weight);
            e += weight;
        }

        while (s < e) {

            int m = s + (e-s)/2;

            if( canShipWithMinWeight(weights, m, days) ){
                e = m;
            } else{
                s = m+1;
            }
        }
        return s;
    }

    static boolean canShipWithMinWeight(int[] weights, int allowedWeight, int days) {
        int daysNeeded = 1;
        int sum = 0;

        for(int weight : weights){
            if(sum + weight <= allowedWeight){
                sum += weight;
            } else{
                sum = weight;
                daysNeeded++;
            }
        }
        return daysNeeded <= days;
    }

}
