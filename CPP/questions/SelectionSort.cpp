#include <bits/stdc++.h>
// Time complexity is n square O(n2)
// space complexity is O(1) 
// it is not stable but can be made stable using some modification see gfg
// it is inplace algorithm
// no extra space is required
// it is slow sorting algorithm
using namespace std;
int main()
{
    vector<int>v;
    int n;
    cout<<"Enter size of array/vector\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    // Selection sort
    for(int i=0;i<n;i++)
    {
        int sml=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[sml])
            {
                sml=j;
            }
        }
        int temp=v[i];
        v[i]=v[sml];
        v[sml]=temp;
    }
}
