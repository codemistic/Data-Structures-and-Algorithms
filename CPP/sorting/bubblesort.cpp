#include"bits/stdc++.h" //to include all the header files
using namespace std;
void bubble_sort(int arr[],int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n-1-i;j++) 
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);//using inbuilt swap function 
        }
    }
}
int main(){
    int arr[]={2,4,2,77,43,74,354,63,62,6222};
    int n=sizeof(arr)/sizeof(int);
    bubble_sort(arr,n);
    for(auto it: arr){
        cout<<it<<", ";
    }
}
