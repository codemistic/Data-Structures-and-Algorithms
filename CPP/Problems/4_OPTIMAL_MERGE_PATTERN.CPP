// OPTIMAL MERGE PATTERN
// GIVEN N FILES OF DIFFERENT COMPUTATION TIME  , WE HAVE TO JOIN ANY TWO TIMES TOGETHER.AND PUSH IT TO THE LIST
// TILL ONLY 1 TIME LEFT . FIND THE MINIMUM COST TO JOIN ALL TKE ROPES TOGETHER.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }


    
    priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());

    int ans=0;

    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        int new_time=(a+b);
        ans+=new_time;
        pq.push(new_time);
    }
    
    cout<<ans<<endl;
    return 0;
}