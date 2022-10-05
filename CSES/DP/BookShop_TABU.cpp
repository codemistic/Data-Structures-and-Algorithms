#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double; 
#define tcU template<class T
tcU> using V = vector<T>; 
#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=b;i>=a;i--)
#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define precision(n) cout << fixed << setprecision(n)

void setIO(string s) { freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout); }
const int mod = 1e9 + 7;
tcU> T max(T &a,T b) {return a > b ? a : b;}
tcU> T min(T &a, T b) { return a > b ? b : a;}

template<typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
tcU> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
tcU> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }
 
void solve() {
    int n, x; cin >> n >> x;
    vector<int> cost(n); cin >> cost;
    vector<int> weight(n); cin >> weight;
    vector<vector<int>> dp(n+1,vector<int> (x+1,-1));

    for (int i = 0; i <= x; ++i) {
        if (i >= cost[0]) {
            dp[0][i] = weight[0];
        } else dp[0][i] = 0;
    }

    for (int i = 1; i < n; ++i) {
        for (int tar = 1; tar <=x; ++tar) {
            int notake = dp[i-1][tar];
            int take = 0;
            if (tar >= cost[i]) take = dp[i-1][tar-cost[i]] + weight[i];
            dp[i][tar] = max(take,notake);
        }
    }
    cout <<  dp[n-1][x];
}

signed main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

	int T = 1;
	rep(i,1,T+1){
        /* cout << "Case #" << i << ": "; */
        solve();
    }
	return 0;
}

