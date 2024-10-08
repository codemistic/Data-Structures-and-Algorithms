#include <algorithm>
#include <iostream>
#include <vector>
#include<set>
 
using namespace std;
 
int main() {
 
int t;
cin>>t;
while(t--){
	string s;
	cin>>s;
	cout<<s[0];
	for(int i=1;i<s.length()-1;i+=2){
		cout<<s[i];
	}
	cout<<s[s.length()-1]<<endl;
}
return 0;
}
