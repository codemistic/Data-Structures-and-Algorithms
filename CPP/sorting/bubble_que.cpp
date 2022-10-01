#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void check_sort(int arr[],int n){
     bool ans;
     for (int i = 0; i < n-1; i++) {
         ans=false;
         for (int j = 0; j < n-1-i; j++) {
             if(arr[j]>arr[j+1]){
                 swap(arr[j],arr[j+1]);
                 ans=true;
             }
         }
         if(ans==false)
             break;
     }      
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int arr[]={1,3,5,7,9};
    int n=sizeof(arr)/sizeof(int);
    check_sort(arr,n);
    return 0;
}


