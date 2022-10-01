#include<bits/stdc++.h>
using namespace std;
int bin(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (key > arr[mid]) {
			s = mid + 1;

		}
		else {
			e = mid - 1;		}
		}
		return -1;

	}
	void initial() {
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
#endif
	}
	int main() {
		initial();
		int arr[] = {10, 13, 15, 16, 19, 30, 34, 45, 65, 34};
		int key;
		cin >> key;
		int n = sizeof(arr) / sizeof(int);
		int index = bin(arr, n, key);
		if (index != -1) {
			cout << key << " is present at index " << index << endl;
		}
		else {
			cout << "key is not present" << endl;
		}
		return 0;
	}