#include<bits/stdc++.h>
using namespace std;


void sorty(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int key=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[key]){
                key=j;
                
            }
        }
    swap(arr[key],arr[i]);
    }
}
signed main(){
    int arr[]={3,2,1,5,4};
    int n=sizeof(arr)/sizeof(int);
    sorty(arr,n);
    for(auto it: arr){
        cout<<it<<", ";
    }
}
