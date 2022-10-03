// 509- Leetcode https://leetcode.com/problems/fibonacci-number/
```
class Solution {
public:
    double PHI = 1.6180339;
    int fib(int n) {
    
    double ratio = (sqrt(5) + 1) / 2;
        
    double uptopowers = 1;
       while (n > 0) 
       {
           if(n & 1) // n is odd
           {
               uptopowers *= ratio;
           }
           
           ratio = ratio * ratio;
           n = n >> 1; // n = n / 2;
       }
        
        return round(uptopowers / sqrt(5));
        
          }
};
```
*Other different approaches*
```  
/*
        // dp memoization approach
        
         int dp[n+1]={-1};
         if(n==0) return 0;
         if(n==2||n==1) return 1;
         if(dp[n]!=-1)
             return dp[n];
         dp[n]= fib(n-1)+ fib(n-2);
         return dp[n];
        
        // dp- bottom up approach
        
         int fb[n+1];
         if(n<=1) return n;
         fb[0] = 0;
         fb[1] = 1;
         for(int i=2;i<=n;i++){
             fb[i] = fb[i-1] + fb[i-2];
        }
        return fb[n];
        
        
         //space optimized approach
        
         int a=0, b=1, c=0, ans=0;
         if(n==2||n==1) return 1;
         for(int i = 2; i<=n; i++){
            c = a+b;
             a=b;
             b=c;
             ans=c;
         }
         return ans;
        
         int f[6] = { 0, 1, 1, 2, 3, 5 };
        
          if (n < 6)
        return f[n];
 
        int t = 5, fn = 5;
         while (t < n) {
             fn = round(fn * PHI);
             t++;
         }
     return fn;
     */
     ```   
