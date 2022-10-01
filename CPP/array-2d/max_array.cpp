// #include<bits/stdc++.h>
// using namespace std;
// void initial(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
// }
// int main(){
// 	initial();
// 	int a[]={112,113,44,555,77665,787654};
// 	int n= sizeof(a)/ sizeof(int);
// 	cout<<"maximum ="<<*max_element(a,a+n);
// 	return 0;
// }




#include<bits/stdc++.h>
using namespace std;
int max_arr(int arr[],int n){
	int max=arr[0];

	for (int i = 1; i < n; ++i)
	{
		if (max<arr[i])
		{
			max=arr[i];
		}

	}
	cout<<max<<endl;

	return 0 ;
}
void initial(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}
int main(){
	initial();
	int arr[]={12,13,14,15,17776,177};
	int n = sizeof(arr)/ sizeof(int );





	max_arr(arr,n);
	return 0;
}