// Q173 https://www.codingninjas.com/codestudio/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0




// Recursion
// Time: O(2^n)
// Space: O(n) 
#include<bits/stdc++.h>
int ks(vector<int> &val, vector<int> &wt, int ind, int W){
    if(ind==0) {
        if(wt[0]<=W) return val[0];
        return 0;
    }
    int nt=ks(val,wt,ind-1,W);
    int t=INT_MIN;
    if(wt[ind]<=W)
        t=val[ind]+ks(val,wt,ind-1,W-wt[ind]);
    return max(t,nt);
}

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    return ks(val,wt,n-1,W);
}


// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
#include<bits/stdc++.h>
int ks(vector<int> &val, vector<int> &wt, int ind, int W,vector<vector<int>> &dp){
    if(ind==0) {
        if(wt[0]<=W) return val[0];
        return 0;
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nt=ks(val,wt,ind-1,W,dp);
    int t=INT_MIN;
    if(wt[ind]<=W)
        t=val[ind]+ks(val,wt,ind-1,W-wt[ind],dp);
    return dp[ind][W]=max(t,nt);
}

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return ks(val,wt,n-1,W,dp);
}





// DP
// Time: O(N*m)
// Space: O(N*M)
#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int cw=0;cw<W+1;cw++) dp[0][cw]=val[0];
     for(int ind=1;ind<n;ind++){
         for(int cw=0;cw<=W;cw++){
             int nt=dp[ind-1][cw];   
             int t=INT_MIN;
             if(wt[ind]<=cw)
                 t=val[ind]+dp[ind-1][cw-wt[ind]];
             dp[ind][cw]=max(t,nt);
         }
         
     }
//      for(int ind=0;ind<n;ind++){
//          for(int cw=0;cw<=W;cw++){
//              cout<<dp[ind][cw]<<" ";
//          }
//          cout<<endl;
//      }
 
     return dp[n-1][W];
 
}

// TABULATION
// Time: O(N*m)
// Space: O(2*M)
#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W){
    vector<int> p(W+1,0);
    vector<int> c(W+1,0);
    for(int cw=wt[0];cw<W+1;cw++) p[cw]=val[0];
     for(int ind=1;ind<n;ind++){
         for(int cw=0;cw<=W;cw++){
             int nt=p[cw];   
             int t=INT_MIN;
             if(wt[ind]<=cw)
                 t=val[ind]+p[cw-wt[ind]];
             c[cw]=max(t,nt);
         }
         p=c;
         
     }
     return p[W];
 
}



// SINGLE ARRAY TABULATION
// Time: O(N*m)
// Space: O(M)
#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W){
    vector<int> p(W+1,0);
//     vector<int> c(W+1,0);
    for(int cw=wt[0];cw<W+1;cw++) p[cw]=val[0];
     for(int ind=1;ind<n;ind++){
         for(int cw=W;cw>=0;cw--){
             int nt=p[cw];   
             int t=INT_MIN;
             if(wt[ind]<=cw)
                 t=val[ind]+p[cw-wt[ind]];
             p[cw]=max(t,nt);
         }
//          p=c;
         
     }
     return p[W];
 
}
