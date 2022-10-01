#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void hehe(int n){
	
	if(n==0) return;
	cout<<n--<<" ";
	hehe(n);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	hehe(n);
	
	return 0;
}
