// Problem Link - https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

/*Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array. */

// CODE

int longestSubsequence(int n, int arr[])
    {
       int dp[n];
       dp[0] = 1;
       
       for(int i = 1;i<n;i++){
           dp[i] = 1;
           for(int j = 0;j<i;j++){
               if(arr[i] > arr[j] and dp[i] < dp[j]+1){
                   dp[i] = dp[j] + 1;
               }
           }
       }
       
       return *max_element(dp,dp+n);
    }

    