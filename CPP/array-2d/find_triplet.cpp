
#include<iostream>
using namespace std;
void exp(int arr[],int n,int target){
    for(int i=0;i<n;i++){      
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==target){
                    if(arr[i]<arr[j]&&arr[j]<arr[k]){
                    cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
                    }
                }
            }
        }
    }
}
int main(){
    int arr[]={2,7,4,0,9,5,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=6;
    exp(arr,n,target);
    return 0;
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Te
