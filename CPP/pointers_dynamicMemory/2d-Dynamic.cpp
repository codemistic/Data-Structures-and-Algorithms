#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;

    // creation of 2array
    //
    int **arr= new int *[n];
    for (int i = 0; i < n; i++) {
    arr[i]= new int[n];

    }
    // taking input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }
    // giving the outputl
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //releasing of all the heap memory
    for (int i = 0; i < n; i++) {
        delete [] arr[i];

    }
    delete []arr;
    return 0;
}


