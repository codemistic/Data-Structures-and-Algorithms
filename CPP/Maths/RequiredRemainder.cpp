#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
 
 
int main()
 
{
 
int t;
cin>>t;
int x,y,n,k;
for(int i=0;i<t;i++){
    cin>>x>>y>>n;
    if((n-n%x+y)<=n){
        cout<<n-n%x+y<<endl;
    }
    else{
        cout<<n-n%x+y-x<<endl;
    }
}
return 0;
}
