#include <iostream>
using namespace std;

void binary(int n){
    if(n==0){
        return;
    }
    binary(n/2);
    cout<<(n%2);
}

int main(){
    int n;
    cin>>n;
    binary(n);
    return 0;
}
