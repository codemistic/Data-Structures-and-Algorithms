public class CapacitytoShipPackageswithinDDays {
    public static void main(String args[])
    {
        int[] weights={1,2,3,4,5,6,7,8,9,10};
        int days=5;
        int result=shipWithinDays(weights,days);
        System.out.println("The least weight capacity of the ship is : "+result);

    }
    public static int shipWithinDays(int[] weights, int days) {
        int left=0;
        int right=0;
        for(int weight:weights)
        {
            left=Math.max(left,weight);
            right+=weight;
        }
        int answer=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(canShip(weights,days,mid))
            {
                answer=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return answer;
    }
    public static boolean canShip(int[] weights,int days,int capacity)
    {
        int totalDays=1;
        int currentLoad=0;
        for(int weight:weights)
        {
            currentLoad+=weight;
            if(currentLoad<=capacity)
            {
                continue;
            }
            else{
                totalDays++;
                currentLoad=weight;

            }
        }
        return totalDays<=days;
    }
}
