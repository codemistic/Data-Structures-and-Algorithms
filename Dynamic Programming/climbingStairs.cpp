// Leetcode-70 Climbing Stairs  https://leetcode.com/problems/climbing-stairs/
/*
**the idea is very simple, just think of it like fibonacci problem. Here, only the initial condition is modified.
Each time you can either climb 1 or 2 steps
for n = 1, you just have 1 step
for n = 2, you have 2 steps(1+1,2)
// fibonacci condition - if(n==1||n==2) return 1;
so, the initial fibonacci condition gets modified to
if(n==1||n==2) return n;

**
*/
```
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, c = 0, ans=0;
        if(n==1||n==2) return n;
        for(int i = 3; i<=n; i++){
            c = a+b;
            a=b;
            b=c;
            ans = c;
        }
        return ans;
    }
};
```
