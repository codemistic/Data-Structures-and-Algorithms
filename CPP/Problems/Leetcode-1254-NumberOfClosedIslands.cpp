#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1) {
            return;
        }
        
        grid[i][j] = 1;
        dfs(i + 1, j, grid, n, m);
        dfs(i, j + 1, grid, n, m);
        dfs(i - 1, j, grid, n, m);
        dfs(i, j - 1, grid, n, m);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            dfs(i, 0, grid, n, m);
            dfs(i, m - 1, grid, n, m);
        }
        for(int j = 0; j < m; j++) {
            dfs(0, j, grid, n, m);
            dfs(n - 1, j, grid, n, m);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        
        return count;
    }
};