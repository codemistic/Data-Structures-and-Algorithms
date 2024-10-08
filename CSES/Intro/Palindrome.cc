#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    map<char,int>m;
    for (auto i : s) m[i]++;

    int odd = 0;
    char L;
    for (auto i : m) {
        if (i.second % 2 != 0) {
            L = i.first;
            odd++;
        }
    }
    if (odd > 1) {
        cout << "NO SOLUTION\n";
    } else {
        string ans="";
        if (odd !=0) ans.push_back(L);
        for (auto i : m) {
            string R(i.second/2, i.first);
            string C = R;
            C += ans;
            ans = C;
            reverse(R.begin(),R.end());
            ans += R;
        }
        cout << ans << '\n';
    }
	return 0;
}


