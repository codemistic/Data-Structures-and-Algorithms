#include<bits/stdc++.h>
using namespace std;

int getHCF(int a,int b){
    if(b==0) return a;
    return getHCF(b,a%b);
}

int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    int HCF=getHCF(a,b);

    // LCM=(a*b)/hcf(a,b);

    int LCM=(a*b)/HCF;
    cout<<"The LCM of "<<a<<" and "<<b<<" is "<<LCM<<endl;
    return 0;
}

//Time Complexity: O(log(b));
//Space Complexity: O(1);