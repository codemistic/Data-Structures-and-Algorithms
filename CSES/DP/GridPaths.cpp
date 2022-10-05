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
 
int f(int i,int k,vector<vector<char>> &grid,vector<vector<int>> &dp) {
    if (i < 0 || k < 0 ) return 0;
    if (i == 0 && k == 0 && grid[i][k] != '*') return 1;

    if (grid[i][k] == '*') return 0;
    if (dp[i][k] != -1) return dp[i][k];
    int one = f(i-1,k,grid,dp) % mod;
    int second = f(i,k-1,grid,dp) % mod;
    return (dp[i][k] = (one + second) %mod) %= mod;
}

void solve() {
    int N; cin >> N;
    vector<vector<char>> grid(N,vector<char> (N));
    vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
    rep(i,0,N) {
        rep(k,0,N) {
            cin >> grid[i][k];
        }
    }
    cout << f(N-1,N-1,grid,dp) << '\n';
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

