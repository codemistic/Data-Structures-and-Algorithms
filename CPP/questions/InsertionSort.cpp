#include <bits/stdc++.h>
// Time complexity in worst case is n square O(n2)
// and best case is O(n) if already sorted
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
    for(int i=1;i<n;i++)
    {
        int val=v[i];
        int j=i;
        while(j>0&&v[j-1]>val)
        {
            v[j]=v[j-1];
            j--;
        }
        v[j]=val;
    }
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
}
