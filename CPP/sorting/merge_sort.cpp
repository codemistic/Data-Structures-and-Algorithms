#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

void merge(std::vector<int> &v,int s,int e){
	int i=s;
	int mid=(s+e)/2;
	int j=mid+1;
	std::vector<int> temp;
	 while(i<=mid && j<=e)//this will break if one of the array gets exausted
	 {
	 	if(v[i]<v[j]){
	 		temp.pb(v[i]);
	 		i++;

	 	}
	 	else
	 	{
	 		temp.pb(v[j]);
	 		j++;
	 	}	
	 }
	 //first array me se baaki ke element ko copy krnge temp me
	 while(i<=mid)
	 {
	 	temp.pb(v[i]);
	 	i++;
	 }
	 //second array me se baaki ke element ko copy krnege temp me
	 while(j<=e)
	 {
	 	temp.pb(v[j]);
	 	j++;
	 }
	 //now we will transfer all the element for sorted array i.e temp to
	 //the unsorted array i.e vector v

	 int he=0;
	 for (int i = s; i <=e; ++i)

	 {
	 	/* code */
	 	v[i]=temp[he];
	 	he++;
	 }
	}
	void mergesort(std::vector<int> &v,int s,int e){
		if(s>=e) return;
		int mid=(s+e)/2;
		mergesort(v,s,mid);
		mergesort(v,mid+1,e);
		return merge(v,s,e);
	}
	int main(){
	//cin.tie(0)->sync_with_stdio(0);
		int n;
		cin>>n;
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int it;
			cin>>it;
			v.pb(it);
		}
		int s=0;
		int e=n-1;
		mergesort(v,s,e);
		for(auto it: v)
			cout<<it<<" ";
		
		return 0;
	}
