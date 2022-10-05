/*
 * 
 * Minimum Time to make the Rope Colorful.
 * Leetcode Question - 1578.
 * 
 * In this code I have used the Greedy Approach To solve this question.
 */


public class MinimumTimeToColorRope {
    public static void main(String[] args) {
        int time[] = {1,2,3,4,5};                               //Time in Seconds
        String colors = "abaac";                                //Colors Sequence
        System.out.println(minCost(colors, time));              //Total Time Taken to make the rope colorfull
    }
    public static int minCost(String colors, int[] neededTime) {
        int sec = 0;
        char c = ' ';
        int cp = 0;
        for(int i=0;i<colors.length();i++)
        {
            if(colors.charAt(i) == c)
            {
                if(cp < neededTime[i])
                {
                    sec += cp;
                    cp = neededTime[i];
                }
                else
                    sec += neededTime[i];
            }
            else
            {
                c = colors.charAt(i);
                cp = neededTime[i];
            }
        }
        return sec;
    }
}
