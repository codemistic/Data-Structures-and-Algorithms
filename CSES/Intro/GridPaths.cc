#include <bits/stdc++.h>
using namespace::std;

static int cnt = 0;
bool vis[7][7];
string s; 

// pruning
bool e(int i,int j) { return (i >= 0 && i < 7 && j < 7 && j >=0 && !vis[i][j]); }

void dfs(int i,int j,int idx) {
    if (i == 6 && j == 0) {
        if (idx == 48) cnt++;
        return; // optimisation 2
    }
    if (vis[i][j] == true) return;
    vis[i][j] = true;
    if (s[idx] == '?' || s[idx] == 'L') {
        if (j && !vis[i][j-1]) {
            if ((e(i,j-2)==false && e(i+1,j-1) && e(i-1,j-1)) == false){
                dfs(i,j-1,idx+1);
            }
        }
    }
    if (s[idx] == '?' || s[idx] == 'R') {
        if (j < 6 && !vis[i][j+1]) {
            if ((e(i,j+2) == false && e(i+1,j+1) && e(i-1,j+1)) == false) {
                dfs(i,j+1,idx+1);
            }
        }
    }
    if (s[idx] == '?' || s[idx] == 'U'){
        if (i && !vis[i-1][j]) {
            if ((e(i-2,j) == false && e(i-1,j+1) && e(i-1,j-1)) == false) {
                dfs(i-1,j,idx+1);
            }
        }
    }
    if (s[idx] == '?' || s[idx] == 'D') {
        if (i < 6 && !vis[i+1][j]) {
            if ((e(i+2,j) == false && e(i+1,j+1) && e(i+1,j-1)) == false) {
                dfs(i+1,j,idx+1);
            }
        }
    }

    vis[i][j] = false; // backtrack
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    cin >> s;
    dfs(0,0,0);
    cout << cnt << endl;
	return 0;
}


// we only done 2 optimisation
// 1st is if we have reached at the end early  then return OPT1
// 2nd if we reached at the wall end and only can move right or left then return OPT2
//3rd if can move only left and right and already visited one then return  
//4th if diagonal already visited return
