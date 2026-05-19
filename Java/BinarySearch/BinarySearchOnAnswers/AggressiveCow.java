public class AggressiveCow {
    public static void main(String args[])
    {
        int[] stalls={1,2,4,8,9};
        int cows=3;
        int result=aggressiveCows(stalls,cows);
        System.out.println("The largest minimum distance is : "+result);
    }
    public static int aggressiveCows(int[] stalls,int cows)
    {
        int left=1;
        int right=stalls[stalls.length-1]-stalls[0];
        int answer=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(canPlaceCows(stalls,cows,mid))
            {
                answer=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return answer;
    }
    public static boolean canPlaceCows(int[] stalls,int cows,int distance)
    {
        int countCows=1;
        int lastPosition=stalls[0];
        for(int i=1;i<stalls.length;i++)
        {
            if(stalls[i]-lastPosition>=distance)
            {
                countCows++;
                lastPosition=stalls[i];
               
            }
        }
        return countCows>=cows;
    }
}
