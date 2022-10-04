// https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int x) {
        return x && (!(x&(x-1)));
    }
};