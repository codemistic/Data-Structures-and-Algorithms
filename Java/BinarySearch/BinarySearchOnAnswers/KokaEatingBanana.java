
 //Binary Search on Answers
 //monotonic function 
        //CanEat - > F F F T T T
        //We need to find first T ( Minimum k)

        //Time Complexity - O(N log M) where N is number of piles and M is max pile size
        //Space Complexity - O(1)

public class KokaEatingBanana {
    public static void main(String args[])
    {
        int piles[]={3,6,7,11};
        int h=8;

       
        int low=1;
        int high=0;
        for(int i=0;i<piles.length;i++)
        {
            high=Math.max(high,piles[i]);
        }
        int result=high;
        while(low<=high)
        {
            int mid=(low)+(high-low)/2;
            if(canEat(piles,mid,h))
            {
                result=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        System.out.println("Minimum Eating Speed: "+result);

    }
    static boolean canEat(int piles[],int k,int h)
    {
        int hours=0;
        for(int i=0;i<piles.length;i++)
        {
            hours+=Math.ceil((double)piles[i]/k);
        }
        return hours<=h;
    }
}
