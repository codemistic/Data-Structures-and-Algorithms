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
#define nline '\n'
 
void setIO(string s) { freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout); }
const int mod = 1e9 + 7;
tcU> T max(T a,T b) {return a > b ? a : b;}
tcU> T min(T a, T b) { return a > b ? b : a;}
 
template<typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
tcU> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
tcU> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }
 
void solve() {
    int n; cin >> n;
    vector<ll> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        ll ways = 0;
        for (int k = 1; k <= 6; ++k) {
            if ((i-k) >= 0) {
                (ways += dp[i-k]) %= mod;
            }
        }
        (dp[i] = ways) %= mod;
    }
    cout << dp[n] % mod << '\n';
}
 
signed main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
 
	int T = 1;
	/* cin >> T; */
	rep(i,1,T+1){
        /* cout << "Case #" << i << ": "; */
        solve();
    }
	return 0;
}
