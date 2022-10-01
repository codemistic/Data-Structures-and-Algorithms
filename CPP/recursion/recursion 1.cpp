#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)
#define vfr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x
#define llread(x) long long x;cin>>x

using namespace std;
void func(int n){
	if(n==0) return;
	func(n-1);//    OUTPUT 1 2 3 4 5
	cout<<n<<endl;
	// cout<<n<<endl;  OUTPUT 5 4 3 2 1
	// func(n-1);
}
int fact(int n){
	if(n==0) return 1;
	return fact(n-1)*n;
}
int main(){
	read(n);
	cout<<fact(n)<<endl;
		
	return 0;
}
