
/*1402_A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000
*/
import java.util.*;
class Solution {
    int[][] dp;
    int max=Integer.MIN_VALUE;
    public int maxSatisfaction(int[] satisfaction) {
    dp=new int[satisfaction.length][satisfaction.length];
    Arrays.sort(satisfaction);
    /*for(int i=0;i<dp.length;i++){
        for(int j=0;j<dp[0].length;j++){
            dp[i][j]=-1;
        }
    }*/
    
    return solveSO(satisfaction);
    
    }
    public int solveTab(int[] sat){
    int[][] dp=new int[sat.length+1][sat.length+1];
    for(int i=0;i<dp.length;i++){
        for(int j=0;j<dp.length;j++){
        dp[i][j]=0;    
        }
    }
            for(int i=sat.length-1;i>=0;i--){
        for(int j=0;j<sat.length;j++){
  int val=sat[i]*(j+1);
        int include=val+dp[i+1][j+1];
        int exclude=dp[i+1][j];  
        dp[i][j]=(int)Math.max(include,exclude);
        }
    }
    return dp[0][0];
    }
      public int solveSO(int[] sat){
    int[] curr=new int[sat.length+1];
    int[] prev=new int[sat.length+1];   
    int max=Integer.MIN_VALUE;
    for(int i=0;i<dp.length;i++){
   prev[i]=0;curr[i]=0;
    }
            for(int i=sat.length-1;i>=0;i--){
        for(int j=0;j<sat.length;j++){
  int val=sat[i]*(j+1);
        int include=val+prev[j+1];
        int exclude=prev[j];  
        curr[j]=(int)Math.max(include,exclude);
        max=(int)Math.max(curr[j],max);
        }
        prev=curr;
        curr=new int[sat.length+1];
                
    }
    return prev[0];
    }
    public int maxLikeTime(int[] sat,int i,int j){
        if(i>=sat.length){
        
            return 0;
        }
        if(dp[i][j]!=-1){
            
        
            return dp[i][j];
        }
        int val=sat[i]*(j+1);
        int include=val+maxLikeTime(sat,i+1,j+1);
        int exclude=maxLikeTime(sat,i+1,j);
    
        

        
        dp[i][j]=(int)Math.max(include,exclude);
        max=(int)Math.max(include,exclude);
        return dp[i][j];
        
    }
}