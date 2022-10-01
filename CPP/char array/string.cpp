#include<bits/stdc++.h>
using namespace std;
string palindrome(string s){
	
	for (int i = 0; i <s.size()/2; ++i)
	{
		if(s[i]!=s[s.size()-i-1]){
			return "no";
	
		}

	}
	return "yes";
}
int main(){
	/*string s;
	s="siddhu";
	s[0]='S';
	cout<<s<<endl;
	cout<<s.size()<<endl;*/
	/*int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		cout<<s<<endl;
	}*/
	string s;
	cin>>s;
	cout<<palindrome(s);


/*	string s_rev;

	for (int i = s.size()-1; i >=0; --i)

	{
		s_rev.push_back(s[i]);
	}
	cout<<s_rev<<endl;*/
	// ********PALINDROME**********
	/*if(s==s_rev){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;*/
	return 0;
}
