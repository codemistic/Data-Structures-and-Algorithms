#include <bits/stdc++.h>
using namespace::std;
int cnt = 0;
vector<pair<int,int>> ans;

void f(int n,int from,int to,int aux) {
    if (n == 0) return;
    cnt++;
    f(n-1,from,aux,to);
    ans.push_back({from,to});
    f(n-1,aux,to,from);
}

int solve(int n) {
    f(n,1,3,2);
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n; cin >> n;
    cout << solve(n) << endl;
    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
	return 0;
}


