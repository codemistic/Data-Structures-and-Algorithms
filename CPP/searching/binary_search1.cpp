#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
int firstocc(vector<int>& arr,int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    for (int i = 0; i < n; i++) {
        int mid=(s+e)/2;    
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(key>arr[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return ans;
    
}
int lastocc(vector<int>& arr,int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;
    for (int i = 0; i < n; i++) {
        int mid=(s+e)/2;    
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(key>arr[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return ans;
    
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int &val : arr) {
        cin >> val;
    }
    int key;
    cin>>key;
    cout<<"first occurrence is :"<<firstocc(arr,n,key);
    
     cout<<"last occurrence is :"<<lastocc(arr,n,key);
    return 0;
}


