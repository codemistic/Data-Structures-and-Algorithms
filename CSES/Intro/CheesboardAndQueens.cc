#include <bits/stdc++.h>
using namespace::std;
#define N 8

char grid[8][8];
static int cnt = 0;

bool is_safe(int row,int col){
    int i, j;
  
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (grid[row][i] == 'G')
            return false;
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (grid[i][j] == 'G')
            return false;
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (grid[i][j] == 'G')
            return false;
  
    return true;
}

void dfs(int row,int col) {
    if (col >= N) { cnt++; return; }

    for (int i = 0; i < 8; ++i) {
        if (grid[i][col] != '*' && is_safe(i,col)) {
            grid[i][col] = 'G';
            dfs(i,col+1);
            grid[i][col] = '.';
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    for(int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> grid[i][j];
        }
    }
    dfs(0,0);
    cout << cnt << endl;
	return 0;
}


