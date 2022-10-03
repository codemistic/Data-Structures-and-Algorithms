#include<bits/stdc++.h>
using namespace std;
int main(){

//Pair is a way of creating a Composite datatypes
// pair<int,int> p; //a pair of 2 ints
// pair<int,string> p; //a pair of an int and a string
// pair<vector<int>,string> p; //a pair of a (vector of int) and a string 

//accessing the elements using .first and .second
pair<string,int> p={"hello", 6};
cout<<p.first<<" "<<p.second; //prints: hello 6

//Advantages: in case, you want to return multiple values from a function.

//pair<vector<pair<int,vector<int>>>, string>

pair<int,string> a={4, "xyz"};
p.first = 13;
cout<<p.first<<" "<<p.second;

}
