#include<bits/stdc++.h>
using namespace std;

int getPower(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b/=2;
    }
    return ans;
}

int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    int answer=getPower(a,b);
    cout<<"The value of "<<a<<" to the power "<<b<< " is "<<answer<<endl;
    return 0;
}


// Time complexity=O(log(b));
// Space Complexity=O(1);