#include <bits/stdc++.h>
using namespace std;



class  Solution{

    public:
    long long trappingWater(int arr[], int n){
        long long mxR[n];
        long long mxL[n];
        mxL[0] = arr[0];
        mxR[n-1] = arr[n-1];
        for(int i =1;i<n;i++){
            if(mxL[i-1]>arr[i]){
                mxL[i] = mxL[i-1];
            }
            else{
                mxL[i] = arr[i];
            }
        }
        for(int i =n-2;i>=0;i--){
            if(mxR[i+1]>arr[i]){
                mxR[i] = mxR[i+1];
            }
            else{
                mxR[i] = arr[i];
            }
        }
        long long water[n];
        for(int i =0;i<n;i++){
            water[i] = min(mxR[i],mxL[i]) - arr[i];
        }
        long long sum =0;
        for(int i =0;i<n;i++){
            sum = sum+ water[i];
        }
        return sum;
    }
};
	

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n ;
		cin>>n;

		int a[n];

		for(int i = 0;i<n;i++)
			cin >> a[i];

		Solution obj;
		cout<<obj.trappingWater(a, n)<<endl;

		}

return 0;

}
