#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int calPoints(vector<string>&ops) {
    stack<int>score;
    int sum=0;
    for(int i=0; i<ops.size(); i=i+1) {
        if(ops.at(i)=="C") {
            score.pop();
        }
        else if(ops.at(i)=="D") {
            score.push(2*score.top());
        }
        else if(ops.at(i)=="+") {
            int a=score.top();
            score.pop();
            int b=score.top();
            score.push(a);
            score.push(a+b);
        } 
        else {
            int num=stoi(ops.at(i));
            score.push(num);
        }
    }
    while(!score.empty()) {
        sum=sum+score.top();
        score.pop();
    }
    return sum;
}

int main() {
    vector<string>ops={"5","2","C","D","+"};

    cout << calPoints(ops);
    return 0;
}