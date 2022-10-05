#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
 
 
 
int main()
 
{
 

long long n;
cin>>n;
long long arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
sort(arr,arr+n);
cout<<min(arr[n-2]-arr[0],arr[n-1]-arr[1]);
return 0;
}
