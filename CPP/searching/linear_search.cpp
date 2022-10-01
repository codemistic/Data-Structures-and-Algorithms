#include<bits/stdc++.h>
using namespace std;
int linear(int arr[], int key, int n){
    for (int i = 0; i < n; ++i)
    {
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
void initial(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main(){
    initial();
    int arr[]={12,13,14,44,55,66,67,88};
    int key;
    cin>>key;
    int n= sizeof(arr)/ sizeof(int);
    int index= linear(arr,key,n);
    if (index!=-1)
    {
        cout<<key<<" is present at"<<index<<endl;
    }
    else{
        cout<<key<<" is not present"<<endl;
    }
    
    return 0;
}
