class Solution {
public:
    bool isPowerOfFour(int n) {
        // Base Cases
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        
        // Check remainder is 0 or not when divided by 3, and recursion call.
        return (n % 4 == 0) && (isPowerOfFour(n/4));
    }
};