#include"bits/stdc++.h"
using namespace std;
void buble_sort(int arr[],int n){
    for (int i = 0; i <= n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
int main(){
    int arr[]={2,4,2,77,43,74,354,63,62,6222};
    int n=sizeof(arr)/sizeof(int);
    buble_sort(arr,n);
    for(auto it: arr){
        cout<<it<<", ";
    }
}
