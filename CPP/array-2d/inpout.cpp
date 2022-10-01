#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void printarr(int arr[][1000],int n,int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<arr[i][j]<<" ";
        }
       cout<<endl; 
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int arr[1000][1000];
    int n,m;
    cin >>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
        
    }
    printarr(arr,n,m);
    return 0;
}


