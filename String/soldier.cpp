#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#define ll long long
#define dd double
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	ll n, m, k; cin >> n >> m >> k;
	ll sum = 0;
	for (ll i = 1; i <= k; i++) {
		sum += n * i;
	}
	sum -= m;
	if (sum <= 0) {
		cout << "0" << endl;
	}
	else {
		cout << sum << endl;
	}
}
