// Given a two-dimensional list of integers matrix containing 1s and 0s, return the total number of square submatrices with all 1 s.
// https://binarysearch.com/problems/Count-Square-Submatrices

#include<bitmasking/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    for(int i=1; i < n ; i++){
        for(int j = 1; j < m; j++){
            if(mat[i][j]==1){
                mat[i][j]=min({mat[i][j-1],mat[i-1][j-1],mat[i-1][j]})+1;
            }
            ans += mat[i][j];
        }
    }
    for(int i=0; i < n; i++)
        ans+=mat[i][0];
    for(int i=0; i < m; i++)
        ans+=mat[0][i];
    return ans-mat[0][0];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0; i < n;i++){
        for(int j=0; j < m; j++)
            cin>>arr[i][j];
    }
    cout<<solve(arr);
    return 0;
}