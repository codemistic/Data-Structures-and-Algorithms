#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    for(int i = 0; i <(1<<N); ++i) {
        int GC = (i^(i>>1));
        bitset<32>B = GC;
        for(int k = 0; k < N; ++k) {
            cout << B[k];
        }
        cout << '\n';
    }
    return 0;
}

// 00,  01,  11, 10
// 0th, 1th, 2th, 3th
