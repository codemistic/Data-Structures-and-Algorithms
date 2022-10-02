#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int>v;
        long long sum =0;
        int i=0;int j=0;
        if(s==0){
            v.push_back(-1);
            return v;
        }
        while(j<n){
            sum = sum + arr[j];
            if(sum<s){
                j++;
            }
            else if (sum == s){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(sum>s){
                while(sum>s){
                    sum = sum-arr[i];
                    i++;
                    if (sum == s){
                        v.push_back(i+1);
                        v.push_back(j+1);
                        return v;
                    }
                }
                j++;
            }
        }
        v.push_back(-1);
        return v;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long s;
		cin>>n>>s;
		int arr[n];
		const int mx = 1e9;
		for(int i =0;i<n;i++)
		{
			cin>>arr[i];
		}
		Solution ob;
		vector<int>res;
		res = ob.subarraySum(arr,n,s);
		
		for(int i =0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;

	}
	return 0;
}