// INDIAN COIN CHANGE PROBLEM
// FROM AN ARRAY OF DENOMINATION AND FOR VALUE X , FIND MININUM NUMBER OF COINS TO MAKE VALUE X

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;


    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end(),greater<int>());
    int coin=0;

    for(int i=0;i<n;i++)
    {
        coin+= x/v[i];
        x-= x/v[i]*v[i];
    }

    cout<<coin<<endl;
    return 0;
}