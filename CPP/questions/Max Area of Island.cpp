https://leetcode.com/problems/max-area-of-island/description/
class Solution {
public:
    
    bool IsVisit(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    
    int f(int i,int j,int n,int m,vector<vector<int>>&grid){
        grid[i][j] = 0;
        
        int cnt = 1;
        if(IsVisit(i+1,j,n,m,grid)){
            cnt+=f(i+1,j,n,m,grid);
        }
        if(IsVisit(i-1,j,n,m,grid)){
            cnt+=f(i-1,j,n,m,grid);
        }
        if(IsVisit(i,j+1,n,m,grid)){
            cnt+=f(i,j+1,n,m,grid);
        }
        if(IsVisit(i,j-1,n,m,grid)){
            cnt+=f(i,j-1,n,m,grid);
        }
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int n = grid.size();
        
        int m = grid[0].size();
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans,f(i,j,n,m,grid));
                }
            }
        }
        
        if(ans == INT_MIN){
            return 0;
        }
        return ans;
    }
};
