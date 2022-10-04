// https://binarysearch.com/problems/Painting-Houses
// You are looking to paint a row of N fences that can be of K different colors. You have a goal of minimizing cost while ensuring that no two neighboring fences are of the same color.

// Given an N by K matrix where the nth row and kth column represents the cost to paint the nth fence with kth color, return the minimum cost which achieves this goal.

// Note: All costs will be integers greater than or equal to 0, and there is guaranteed to be at least 2 possible colors.

// Bonus: solve in \mathcal{O}(1)O(1) space.

#include<bitmasking/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat) {
    int n=mat.size();
    int k=mat[0].size();
    for(int i=1; i < n;i++){
        for(int j=0; j < k;j++){
            int mini = INT_MAX;
            for(int z=0; z < k;z++){
                if(z==j)continue;
                mini = min(mini,mat[i-1][z]);
            }
            mat[i][j]+=mini;
        }
    }
    return *min_element(mat[n-1].begin(),mat[n-1].end());
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