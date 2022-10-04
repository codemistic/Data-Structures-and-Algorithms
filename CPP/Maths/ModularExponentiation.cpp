#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<math.h>
using namespace std;
 
 
 
int main()
 
{
 
 
    #ifndef ONLINE_JUDGE
 
freopen("input.txt","r",stdin);
 
 
freopen("output.txt","w",stdout);
 
#endif
 
int n,m;
cin>>n>>m;
int r=pow(2,n);
cout<<m%r;
return 0;
}
