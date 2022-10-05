#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n; cin >> n;
    int sum = (n*(n+1))/2;
    if (sum % 2 != 0) {
        cout << "NO\n";
        exit(0);
    }
    if (n <= 3) {
        cout << "YES\n";
        cout <<"2" << '\n';
        cout << "1 2" << '\n';
        cout << "1" << '\n';
        cout << "3" << '\n';
        exit(0);
    }

    vector<int> one,second;
    if (n % 2 == 0) {
        for(int i = 1; i <= n; ++i) {
            if (i % 4 == 0 || i % 4 == 1) {
                one.push_back(i);
            } else {
                second.push_back(i);
            }
        }
    } else {
        one.push_back(1);
        one.push_back(2);
        second.push_back(3);
        for (int i = 1; i <= n - 3; ++i) {
            if (i % 4 == 0 || i % 4 == 1) {
                one.push_back(i + 3);
            } else {
                second.push_back(i + 3);
            }
        }
    }

    cout << "YES\n";
    cout << one.size() << '\n';
    for (auto i : one) cout << i << " ";
    cout << '\n';
    cout << second.size() << '\n';
    for (auto i : second) cout << i << " ";
    cout << '\n';
	return 0;
}


