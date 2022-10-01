//This is a medium question of Leetcode
#include <bits/stdc++.h>
using namespace std;
int lcsAlgo(char *s1,char *s2,int m,int n,int memo[1001][1001]){
    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    if(m==0 or n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return memo[m][n]=1+lcsAlgo(s1,s2,m-1,n-1,memo);
    }
    else{
        return memo[m][n]=max(lcsAlgo(s1,s2,m-1,n,memo),lcsAlgo(s1,s2,m,n-1,memo));
    }
}
int main(){
    char S1[] = "ACADB";
    char S2[] = "CBDA";
    int m = strlen(S1);
    int n = strlen(S2);
     int memo[1001][1001]; // This is used to store the computations of the subproblems , since if it appears in other problem we can just see it in this array and compute it.
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
    cout<<"The Length of the longest common subsequence is"<<lcsAlgo(S1, S2, m, n,memo);
}