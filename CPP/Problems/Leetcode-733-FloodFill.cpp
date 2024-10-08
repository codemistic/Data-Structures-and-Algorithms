#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(int sr, int sc, int initColor, int newColor, vector<vector<int>>& grid, 
                vector<vector<int>>& image, int deltaRow[], int deltaCol[]) 
    {
        grid[sr][sc] = newColor;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < 4; i++) {
            int newRow = sr + deltaRow[i];
            int newCol = sc + deltaCol[i];
            //check if color is same as initial color and not already changed
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                && image[newRow][newCol] == initColor && grid[newRow][newCol] != newColor) {
                    dfs(newRow, newCol, initColor, newColor, grid, image, deltaRow, deltaCol);
                }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initColor = image[sr][sc];
        vector<vector<int>> grid = image;
        
        //up, right, down, left
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};
        
        dfs(sr, sc, initColor, newColor, grid, image, deltaRow, deltaCol);
        
        return grid;
    }
};