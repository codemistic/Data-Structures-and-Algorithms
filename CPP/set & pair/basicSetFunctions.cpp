#include<bits/stdc++.h>
using namespace std;
int main(){

//Set is a container which keeps a unique copy of every element in sorted order.

set<int>s; //empty set of integers
//set<string>s; //empty set of strings

s.insert(20);
s.insert(30);
cout<<s.count(10)<<endl;
cout<<s.count(20)<<endl;
cout<<s.count(40)<<endl;
cout<<s.count(30)<<endl;
cout<<s.count(110)<<endl;

s.erase(10);
cout<<s.count(10)<<endl;
/* IMPORTANT FUNCTIONS
s.insert(x); - insert the value x into set, do nothing if already present. O(log N)
s.erase(x); - erase the value x from set if present. O(log N)
s.count(x); -returns 0 if x ain't in the set and 1 if it's there. O(log N) 
s.clear()- erase all elements. O(N)
s.size()- returns the current size of the set. O(1)

WRONG: cout<<s[0]; //operator doesnt work with sets
*/

}
