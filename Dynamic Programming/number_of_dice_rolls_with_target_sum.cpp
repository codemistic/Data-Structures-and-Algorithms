#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[31][1001] = {0}; // Table of n * target sum ; This is used to save the results in bottom up approach
int numRollsToTarget(int n, int k, int target) {
    dp[0][0] = 1; // When you have 0 dices and target sum = 0; the number of ways to get the answer is 1
    
    for(int i = 1;i<=target;i++){ // when you have 0 dices; [1,targetsum] numbers there are zero ways to get the answer
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){ // when you have 0 target; n =[1,n] dices there are zero ways to get the answer
        dp[i][0] = 0;
    }

    /*
    The below loop has Time complexity = O(n*targetSum*k)
    It finds the answer for smaller target sums and build up to find the solution of the targetSum
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            long long res = 0;
            for(int x=1;x<=k;x++){
                if(j>=x){
                    res = (res % 1000000007) + (dp[i-1][j-x] % 1000000007);
                    // res = res % 1000000007;
                }
            }
            dp[i][j] = res ;
        }
    }
    return dp[n][target] % 1000000007;
}

int main(){

    int n = 7,k=6,target = 30;
    cout<<numRollsToTarget(n,k,target)<<endl;
    return 0;
}