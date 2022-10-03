// https://binarysearch.com/problems/Cycle-Detection-in-a-Matrix
// You are given a two-dimensional list of integers matrix. Return whether you can start from some cell, move adjacent to neighboring cells (up, down, left, right) of the same value, and come back to the same starting cell. You can’t revisit a cell you last visited.

vector<vector<int>> nb = {{0,1},{0,-1},{1,0},{-1,0}};

bool helper(vector<vector<int>>& mat,int x,int y,int key,vector<vector<int>>& vis){
    vis[x][y]=1;
    bool ans=0;
    for(int i =0; i < 4; i++){
        int x1 = x+nb[i][0];
        int y1 = x+nb[i][1];
        if(x1 > -1 && x1 < mat.size() && y1 > -1 && y1 < mat[0].size() && mat[x1][y1]==key){
            cout<<" inner loop "<<x1<<" "<<y1<<" "<<ans<<endl;
            if( !vis[x1][y1]){
                ans |=helper(mat,x1,y1,key,vis);
            }
            else if( vis[x1][y1] && (x1 != x || y1 != y)){
                return true;
            }
        }
    }
    cout<<x<<" "<<y<<" "<<ans<<endl;
    return ans;
}

bool solve(vector<vector<int>>& mat) {
    vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
    for(int i=0; i < mat.size();i++){
        for(int j=0; j < mat[0].size();j++){
            if(vis[i][j]==0){
                if(helper(mat,i,j,mat[i][j],vis))return 1;
            }
        }
    }
    return 0;
}