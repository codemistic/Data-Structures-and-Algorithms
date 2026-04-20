#include<bits/stdc++.h>
using namespace std;

void findDivisor(int n){
    cout<<"The Divisors of "<<n<<" are: ";
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i!=n/i){
                cout<<n/i<<" ";
            }
        }
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    findDivisor(n);
    return 0;
}

//Time Complexity: O(sqrt(n));
//Space Complexity: O(1);