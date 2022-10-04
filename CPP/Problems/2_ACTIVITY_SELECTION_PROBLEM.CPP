// GIVEN N ACTIVITIES WITH THEIR START TIME AND FINISH TIME
// FIND MINIMUM NO OF ACTIVITIES THAT CAN BE PERFORMED BY A SINGLE PERSON ,ASSUMING CAN DO SINGLE WORK AT A TIME

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bool compare(pair<int,int> p1,pair<int,int> p2)
// {
//     return p1.second<p2.second;
// }
// int main()
// {
//     int n;
//     cin>>n;

//     vector<pair<int,int>> v;

//     for(int i=0;i<n;i++)
//     {
//         int start,end;
//         cin>>start>>end;

//         v.push_back(make_pair(start,end));

//     }

//     sort(v.begin(),v.end(),compare);

//     int task=1;
//     int new_end=v[0].second;

//     for(int i=1;i<n;i++)
//     {
//         if(v[i].first>=new_end)
//         {
//             task++;
//             new_end=v[i].second;
//         }
//     }

//     cout<<task<<endl;

// }


 bool compare(vector<int> &a,vector<int> &b)
 {
     return a[1]<b[1];
 }


int main()
{
    int n;
    cin>>n;

    vector<vector<int>> v;

    for(int i=0;i<n;i++)
    {
        int start,end;
        cin>>start>>end;

        v.push_back({start,end});

    }

    // sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b)
    // {
    //     return a[1]<b[1];
    // });

    sort(v.begin(),v.end(),compare);

    int task=1;
    int new_end=v[0][1];

    for(int i=1;i<n;i++)
    {
        if(v[i][0]>=new_end)
        {
            task++;
            new_end=v[i][1];
        }
    }

    cout<<task<<endl;

}