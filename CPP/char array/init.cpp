#include<bits/stdc++.h>
#include<cstring>
#define int long long
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x


using namespace std;
signed main(){
	// char a[]={'a','b','c','\0'};
	char a[]= "abcdef";
	
	cout<<a<<endl;
	cout<<strlen(a)<<endl;
	cout<<sizeof(a)<<endl; // here we are getting +1 size because there
	 // is a null char in the string which is being stored.-----
	char xyz[100];
	cin>>xyz;// by using this cin we can only store one 
	// word as a char arrray.-------
	// if we wanna store "hello world" it willl only store
	 // hello as char array.:(-------
	cout<<xyz;

	
	return 0;
}
