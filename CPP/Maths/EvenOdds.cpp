#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
 
 
 
int main()
 
{
 
 
long long n,k;
cin>>n>>k;
if(k<=(n+1)/2){
    cout<<2*k-1;
}
else{
    cout<<(k-(n+1)/2)*2;
}
return 0;
}
