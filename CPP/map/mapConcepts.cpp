```
#include<bits/stdc++.h>>
using namespace std;
int main() {
    
//Map: Commom use- counts frequency of various objects
//Maps are special arrays in which the indices(keys) of elements can be negative or very big or even strings! 

// map<key_datatype, value_datatype> m;

map<string, int>m; //defines a map in which the keys of elements are strings.
m["hello"]=50;
m["world"]=12;
cout<<m["hello"]<<" "<<m["world"]; //50 12

//Maps are very similar to sets, in sets the values are unique and sorted. In maps, the keys are unique and sorted(lexicographically).
return 0;
}
```
