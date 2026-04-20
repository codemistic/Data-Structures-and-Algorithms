#include <bits/stdc++.h>
using namespace std;
//Function to demonstrate monotonic decreasing stack
void decreasingMonotonicStack(vector<int> inputs){

vector<int> stack;
    for(int p:inputs){

while(!stack.empty()  && stack.back()<=p){
    stack.pop_back();
}
stack.push(p);

    }
    for (int val : stack) {
    cout << val << " ";
}
    cout<<endl;
}
// Function to demonstarte monotonic increasing stack
void increasingMonotonicStack(vector<int> inputs){

vector<int> stack;
    for(int p:inputs){

while(!stack.empty()  && stack.back()>=p){
    stack.pop_back();
}
stack.push(p);

    }

    for (int val : stack) {
    cout << val << " ";
}
    cout<<endl;
}
int main(){
vector<int> inputs={3,4,5,6,7,4,5,3};
decreasingMonotonicStack(inputs);
increasingMonotonicStack(inputs);



}