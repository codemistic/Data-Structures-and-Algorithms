#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define read(x) int x;cin>>x


using namespace std;
void counting_sort(int arr[],int n){
	int large=INT_MIN;
	for(int i=0;i<n;i++)
		large=max(large+1,arr[i]);

	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		v[arr[i]]++;
	}
	int z=0;
	for(int i=0;i<n;i++){
		while(v[i]>0){
			arr[z]=i;
			v[i]--;
			z++;
		}
	}

}
void printarray1(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}
signed main(){
	int arr[]={1,1,23,42,11,31,533,7432};
	int n;
	n=sizeof(arr)/sizeof(int);
	counting_sort(arr,n);
	printarray1(arr,n);

	
	return 0;
}
