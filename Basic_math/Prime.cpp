#include<bits/stdc++.h>
using namespace std;
int countPrime(int n){
    if(n==0) return 0;
    int count=0;
    vector<bool>prime(n,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            int j=2*i;
            while(j<n){
                prime[j]=false;
                j+=i;
            }
        }
    }
    return count;
}

int main(){
    int a,b;
    cout<<"Enter a and b :";
    cin>>a>>b;
    int ans1=countPrime(a+1);
    int ans2=countPrime(b);
    cout<<"The total number of prime number between a and b is:"<<(ans2-ans1)<<endl;
    return 0;
}

//Time Complexity: O(nlog(log(n)));
//Space Complexity: O(n);