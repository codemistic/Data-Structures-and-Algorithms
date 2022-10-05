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

int f(int N,vector<int> &dp) {
    if (N <= 0) return 0;

    if (dp[N] != -1) return dp[N];

    int ans = INT_MAX;
    int temp = N;
    while (temp != 0){
        int rem = temp % 10;
        if (rem != 0) {
            int ways = f(N-rem,dp) + 1;
            ans = min(ans,ways);
        }
        temp/=10;
    }
    return dp[N] = ans;
}

void solve() {
    int N; cin >> N;
    vector<int> dp(N+1,-1);
    cout << f(N,dp) << std::endl;
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

