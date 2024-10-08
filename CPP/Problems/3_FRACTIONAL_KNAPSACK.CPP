// GIVEN N ITEMS ( WEIGHT,VALUE) AND WEIGHT OF KNAPSACK W . FIND VALUE OF ITEMS IN KNAPSACK SUCH THAT MAXIMUM

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return ((double)p1.first/p1.second)>((double)p2.first/p2.second);
}

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }

    int w;
    cin>>w;

    sort(v.begin(),v.end(),compare);

    int ans=0;

    for(int i=0;i<n;i++)
    {
        if(w>=v[i].second)
        {
            ans+=v[i].first;
            w-=v[i].second;
        }
        else
        {
            double vw=((double)v[i].first/v[i].second);
            ans+= vw*w;
            w=0;
            break;
        }
    }

    cout<<ans<<endl;

}