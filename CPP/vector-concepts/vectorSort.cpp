// inbuilt sorting in vector
```
#include<bits/stdc++.h>
using namespace std;
int main(){
//sort() can be used to sort array or vector or a string. gcc_sort hybrid algorithm. O(NlogN)

//int a[n]; sort(a,a+n);

//vector<int>v; sort(v.begin(), v.end());

//string s; sort(s.begin(), s.end());

//sort(ptr to 1st element, ptr to last element+1)
int a[4]={5,4,1,2};
//sort(a, a+3); output: 1 4 5 2

// sort(a, a+4); //output 1 2 4 5
// for(int i=0; i<4; i++){ cout<<a[i]<<" ";}

vector<int>v={5,4,1,2};
sort(v.begin(), v.end());
for(int i=0; i<4; i++){ cout<<v[i]<<" ";}
return 0;
}
```
