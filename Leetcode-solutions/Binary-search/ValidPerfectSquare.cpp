// Problem link : https://leetcode.com/problems/valid-perfect-square/
// Time Complexity : O(log(n))

class Solution {
public:
    
    int findSqrt(int num)
    {
        int low = 1;
        int high = num;
        
        int ans;
        
        while(low <= high){
            long long int mid = low + (high - low)/2;
            if(mid * mid <= num){
                ans = mid;
                low = mid + 1;
            }
            else{ // ( mid * mid ) is greater than num
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    bool isPerfectSquare(int num) {
        
        int sqrtN = findSqrt(num);
        
        if((sqrtN * sqrtN) == num) return true;
        
        return false;
    }
};