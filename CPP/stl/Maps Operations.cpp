#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	//key,value pairs like dictionary in python
	map<int,int>mp;
	mp.insert(pair<int,int>(2,20));
	mp.insert(pair<int,int>(3,10));
	
	//mp[key]=value
	mp[4]=80;
	
	cout<<mp.size()<<endl;
	
	for (auto it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	//print value of any particular key in key value pair
	cout<<mp[3]<<endl;
	
	//to delete one key value pair enter the key name of the pair
	mp.erase(2);
	cout<<mp.size()<<endl;
	
	mp.clear();
	if(mp.empty())
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
	return 0;
}
