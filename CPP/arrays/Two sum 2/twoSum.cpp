#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int low = 0,high = n - 1;
        while(low<high){
            int sum = numbers[low] + numbers[high];
            if(sum>target)
                high -= 1;
            else if(sum<target)
                low += 1;
            else{
                res.push_back(low+1);
                res.push_back(high+1);
                break;
            }
        }
        return res;
}
int main(){

    vector<int> numbers({2,3,4});
    int target = 6;
    vector<int> res = twoSum(numbers,target);
    for(auto x:res)
        cout<<x<<endl;
    return 0;
}