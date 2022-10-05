#include <iostream>
using namespace std;

bool subsec(string &s1, string &s2){
    int n=s1.length();
    int m=s2.length();
    int j=0;
    for(int i=0;i<n&&j<m;i++){
        if(s1[i]==s2[j]){
            j++;
        }
    }
    return (j==m);
}

int main(){
    string s1="germany";
    string s2="gmyw";
    cout<<subsec(s1,s2);
    return 0;
}
