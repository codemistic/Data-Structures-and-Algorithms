class Solution {
public:

bool Isvisit(int i,int j,int n,int m, vector<vector<char>>&grid){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1'){
        return true;
    }
    return false;
}

void dfs(int i,int j,int n,int m, vector<vector<char>>&grid){
    grid[i][j] = '0';

    if(Isvisit(i+1,j,n,m,grid)){
        dfs(i+1,j,n,m,grid);
    }
    if(Isvisit(i-1,j,n,m,grid)){
        dfs(i-1,j,n,m,grid);
    }
    if(Isvisit(i,j+1,n,m,grid)){
        dfs(i,j+1,n,m,grid);
    }
    if(Isvisit(i,j-1,n,m,grid)){
        dfs(i,j-1,n,m,grid);
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
