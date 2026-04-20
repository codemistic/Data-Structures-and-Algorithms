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
    int answer=getHCF(a,b);
    cout<<"The HCF of "<<a<<" and "<<b<<" is "<<answer<<endl;
    return 0;
}

//Time Complexity: O(log(b));
//Space Complexity: O(1);