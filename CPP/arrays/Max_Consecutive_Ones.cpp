#include <iostream>
using namespace std;

int maxones(bool a[],int n){
    int res=0,cur=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cur=0;
        }
        else{
            cur++;
            res=max(res,cur);
        }
    }
    return res;
}

int main(){
    bool a[]={1,1,1,0,1,1,1,0,1,0,1,0,1,1};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<maxones(a,n);   // return 3 as max consecutive ones in the array
    return 0;
}
