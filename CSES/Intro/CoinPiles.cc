#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        if(a<b) swap(a,b);

        if (a > 2 * b) {
            cout << "NO\n";
        } else if ((a + b) % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
	return 0;
}

