//ramnit_code_27
#include <bits/stdc++.h>
using namespace std;

int factors(int n){
    int i,count=0;
    vector<int> v;
    for(i=1;i<=n;i++){
        if(n%i==0) {
            v.push_back(i);
            count++;
        }
    }
    cout<<count<<"\n";
    for(int j=0;j<v.size();j++) cout<<v[j]<<" ";
    cout<<"\n";
}

int main() {
	int n;
	cin>>n;
	factors(n);
	return 0;
}
