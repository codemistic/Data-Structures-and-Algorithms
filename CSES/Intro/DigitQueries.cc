#include <bits/stdc++.h>
using namespace::std;

int64_t power(int64_t x,int64_t y) {
    int64_t res = 1;
    while (y > 0) {
        if (y & 1) res = res * x;
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int Q; cin >> Q;
    while (Q--) {
        int64_t K; cin >> K;
        int64_t n = 1, sum = 0;
        
        while (K >= sum) {
            sum = sum + 9 * n * power(10,n-1);
            n++;
        }
        n--;

        // Digits away
        int64_t away = (sum - K) / n;
        int64_t rem = (sum - K) % n;

        // calculate Number
        int64_t number = (power(10,n) - 1) - away;

        string No = to_string(number);
        cout << No[(No.length() - 1 - rem)] << endl;
    }
	return 0;
}


