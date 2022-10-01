		#include<bits/stdc++.h>
		using namespace std;
		int reverse(int arr[], int n){
			int s=0;
			int e= n-1;
			while(s<=e){
				swap(arr[s],arr[e]);
				s+=1;
				e-=1;
			}
			return 0;
		}
		void initial(){
		#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		#endif
		}
		int main(){
		initial();
		int arr[]={12,55,66,77,97,987};
		int n= sizeof(arr)/ sizeof(int);
		reverse(arr,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<arr[i]<<endl;
		}
		

		return 0;
		}
