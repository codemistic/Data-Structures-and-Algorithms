// Problem Link:https://leetcode.com/problems/factorial-trailing-zeroes/submissions/764309899/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        int num=5;
        while((n/num)>0){
            ans+=(n/num);
            num*=5;
        }
        return ans;
    }
};