#include"bits/stdc++.h"
using namespace std;
void insertion_sort(int arr[],int n){
    for (int i = 1; i < n; i++) {
        int temp=arr[i];
        int j=i-1;//we are using j here because we are changing j+1 th elemnt to the temp
        //ulta looop chalake check krenge aur shift krnge(if the element is greater than temp or not
        
        for (;j>=0;j--) {
            if(arr[j]>temp)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=temp;
    }
}
int main(){
    int arr[]={5,3,2,4,1};
    int n=sizeof(arr)/sizeof(int);
    insertion_sort(arr,n);
    for(auto it: arr)
    cout<<it<<", ";
}
