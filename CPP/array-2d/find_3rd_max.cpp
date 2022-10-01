#include<iostream>
using namespace std;
void third(int arr[],int n){
int first=arr[0];
int j=0;
    for(int i=0;i<n;i++)
    {
         if(arr[i]>first)
           first=arr[i];
    }
    int second = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > second && arr[i] < first)
            second = arr[i];

    int third = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > third && arr[i] < second)
            third = arr[i];
    cout<<third;
}
int main(){
    int arr[]={1,34,65,87,9,78};
    int n=sizeof(arr)/sizeof(arr[0]);
    third(arr,n);
    return 0;
}
