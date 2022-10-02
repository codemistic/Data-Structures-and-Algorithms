#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(){
    return {3,4};
}
int main() {
    //sorting array vectors of pairs
    pair<int, int> p[5]; //an array of 5 pairs
    p[0]={1,2}; p[1]={5,2}; p[2]={8,1}; p[3]={1,0}; p[4]={3,4};
    sort(p,p+5);
    cout<<p->first<<" "<<p->second;
    
    return 0;
}
