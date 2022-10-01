#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int check(int arr[],int n,int key){
    int s,e;
    s=0;
    e=n-1;
    int ans=0;
    while(s>=e){
        int mid=s+(s+e)/2;
        if(arr[mid]==key)
            ans=1;
        else if(key>arr[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return ans;
}
string isSubset(int arr1[],int arr2[],int n, int m){
    sort(arr1,arr1+n);
    for (int i = 0; i < m; i++) {
        int thik;
        thik=check(arr2,n,arr1[i]);
        if(thik==1)
            return "Yes";
    }
    return "No";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for (int i = 0; i < n; i++) {
        cin>>arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin>>arr2[i];
    }
    cout<<isSubset(arr1,arr2,n,m);
    return 0;
}


