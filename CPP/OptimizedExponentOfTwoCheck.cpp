#include<bits/stdc++.h>
using namespace std;

bool isAnExponentOfTwo(int n) {
	return ((n & (n-1)) == 0);
}

int main() {
	int n;
	cin >> n;
	cout << (isAnExponentOfTwo(n) ? "YES" : "NO") << endl;
	return 0;
}