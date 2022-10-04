// Memoization
public class Solution {
    public static int matrixMultiplication(int[] arr , int N) {
        if(N < 3) return 0;
        
        int[][] dp = new int[N][N]; 
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dp[i][j] = -1;
        
        return partition(1, N-1, arr, dp);
    }
    
    private static int partition(int i, int j, int[] arr, int[][] dp) {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int min = Integer.MAX_VALUE;
        
        for(int k = i; k < j; k++) {
            int curr = (arr[i-1] * arr[k] * arr[j]) + 
                    partition(i, k, arr, dp) + partition(k+1, j, arr, dp);
            min = Math.min(min, curr);
        }
        
        return dp[i][j] = min;
    }
}

// Tabulation
public class Solution {
    public static int matrixMultiplication(int[] arr , int N) {
        if(N < 3) return 0;
        
        int[][] dp = new int[N][N]; 
        
        for(int i = N-1; i > 0; i--) {
            for(int j = i+1; j < N; j++) {
                if(i == j) continue;
                
                int min = (int) 1e9;
                for(int k = i; k < j; k++) {
                    min = Math.min(min, (arr[i-1] * arr[k] * arr[j]) + 
                                  dp[i][k] + dp[k+1][j]);
                }
                
                dp[i][j] = min;
            }
        }
        
        return dp[1][N-1];
    }
}
