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
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    cin >> coins;
 
    vector<ll>prev(x + 1,0);
    for (ll i = 0; i <= x; ++i) {
        if (i % coins[0] == 0 ) prev[i] = i / coins[0];
        else prev[i] = 1e9;
    }
    for (ll i = 1; i < n; ++i) {
        vector<ll > cur(x + 1, 0);
        for (ll tar = 1; tar <= x; ++tar) {
            ll take = 1e9;
            if (tar >= coins[i]) take = cur[tar-coins[i]] + 1;
            ll notake = prev[tar];
            cur[tar] = min(take,notake);
        }
        prev = cur;
    }
    cout << (prev[x] == 1e9 ? -1 : prev[x]) << '\n';
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
 
