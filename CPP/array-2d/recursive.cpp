#include<iostream>
using namespace std;
bool exp(int arr[],int n,int target,int count=0)
{
    ;
    if(count==3&&target==0)
      return true;
    if(count==3||n==0||target<0)
      return false;
    return exp(arr, n - 1, target - arr[n - 1], count + 1) ||
            exp(arr, n - 1, target, count);
}
int main(){
    int arr[]={ 2, 7, 4, 0, 9, 5, 1, 3 };
    int target = 6;
    int n=sizeof(arr)/sizeof(arr[0]);
    exp(arr,n,target,0)?cout<<"triplets exist":
    cout<<"tripletes doesn't exists";
    return 0;
}
