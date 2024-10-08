// Given two strings a and b of digits, find a way to delete digits in the strings so that:

// The two strings are equal
// The sum of the digits deleted is minimized
// And return this minimized sum. 
// link- https://binarysearch.com/problems/Minimum-Digit-Delete

#include<bits/stdc++.h>
using namespace std;

int helper(string a, string b,int i1,int i2,vector<vector<int>>& dp){
    if(i1 == -1){
        int res = 0;
        for(int i=i2; i >-1; i--)
            res +=(b[i]-'0');
        return res;
    }
    if(i2 == -1){
        int res = 0;
        for(int i=i1; i > -1; i--)
            res +=(a[i]-'0');
        return res;
    }
    if(dp[i1][i2] != -1)return dp[i1][i2];
    if(a[i1]==b[i2])return helper(a,b,i1-1,i2-1,dp);
    int dela = helper(a,b,i1-1,i2,dp)+(a[i1]-'0');
    int delb = helper(a,b,i1,i2-1,dp)+(b[i2]-'0');
    return dp[i1][i2]=min(dela,delb);
}

int solve(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return helper(a,b,a.size()-1,b.size()-1,dp);
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}