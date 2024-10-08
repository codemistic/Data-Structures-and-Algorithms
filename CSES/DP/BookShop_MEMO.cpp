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
 
int f(int idx, int tar, vector<ll> &cost, vector<ll> &weight,vector<vector<ll>> &dp) {
    if (idx == 0) {
        if (tar >= cost[0]) return weight[0];
        return 0;
    }
    if (dp[idx][tar] != -1) return dp[idx][tar];
    int notake = f(idx-1,tar,cost,weight,dp);
    int take = 0;
    if (tar >= cost[idx]) take = f(idx-1,tar - cost[idx], cost, weight,dp) + weight[idx];
    return dp[idx][tar] = max(take , notake);
}

void solve() {
    int n, x; cin >> n >> x;
    vector<ll> cost(n); cin >> cost;
    vector<ll> weight(n); cin >> weight;
    vector<vector<ll>> dp(n+1,vector<ll> (x+1,-1));
    cout << f(n-1,x,cost,weight,dp) << '\n';
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

