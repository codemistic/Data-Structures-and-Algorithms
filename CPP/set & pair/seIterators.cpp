#include<bits/stdc++.h>
using namespace std;
int main(){

//Set iterators offer less features than vectorr iterators.
//auto it = s.begin(); //it is the iterator to the first element
// it++, it--, ++it, --it ->These are all valid and wor in O(log N) time

//NOTE: (it+5) or it+=2 etc are invalid. to advance multiple steps, do it++ multiple times.

//elements of iteratir are always in sorted manner
set<int> s;
s.insert(4);
s.insert(1);
s.insert(10);
s.insert(2);

cout<<*s.begin()<<endl;

s.erase(s.begin());
cout<<*s.begin()<<endl;

/* FUNCTIONS RELATED TO SET ITERATORS:
    s.find(x): returns iterator to element with value x. Returns s.end() if not found. O(log N)

    s.lower_bound(x): returns iterator to the first element which is >=x. Returns s.end() if not found. O(log N)

    s.upperbound(x): returns iterator to the first element which is >x. Returns s.end() if not found. O(log N)

    s.erase(it): erases the element with iterator it. O(log N)

following 2 lines are same
it(s.find(10)==s.end()) cout<<"Not found";
it(s.count(10)==0) cout<<"Not found";
*/
    return 0;
}
