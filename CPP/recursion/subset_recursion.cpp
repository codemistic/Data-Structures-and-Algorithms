#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
vector<vector<int>> ex;
void generate(vector<int> &subset,int i,vector<int> &nums )
{
	if(i==nums.size()){
		ex.pb(subset);
		return ;
	}
	//ith element is not included
	generate(subset,i+1,nums);
	// ith element is included
	subset.pb(nums[i]);
	generate(subset,i+1,nums);
	subset.pop_back();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>nums[i];
	}
	vector<int> emp;
	generate(emp,0,nums);
	for(auto i:ex){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
		
	
	}
	return 0;
}
