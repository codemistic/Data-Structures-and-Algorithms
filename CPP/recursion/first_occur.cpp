#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void findFirstAndLast(int arr[], int n, int x)
{
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (x != arr[i])
            continue;
        if (first == -1)
            first = i;
        last = i;
    }
    if (first != -1)
        cout << "First Occurrence = " << first
             << "\nLast Occurrence = " << last;
    else
        cout << "Not Found";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int arr[]={1,2,4,4,4,6};
	int n=sizeof(arr)/sizeof(int);
	int key;
	key=4;
	findFirstAndLast(arr,n,key);
	
	
	return 0;
}
