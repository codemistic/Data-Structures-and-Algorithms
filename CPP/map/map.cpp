#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x


using namespace std;
signed main(){
	map<int, string> mp;
	mp={{1,"a"},{2,"b"},{6,"c"},{3,"g"}};
	mp[8]="jh";
	// for(auto it:mp)
	// 	cout<<it.first<<" "<<it.second<<endl;
	// mp.erase(8);//O(log (n))
	auto it=mp.find(6);
	if(it==mp.end())
		cout<<"no value"<<endl;
	else
		cout<<(*it).first<<" "<<(*it).second<<endl;
	return 0;
}
//if key and value ae string then compl. is ==O(s.size()*log(n)) 
