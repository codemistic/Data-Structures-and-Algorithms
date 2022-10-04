// https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int rev=0;
        int old=x;
        while(x!=0){
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && rev>7))
                return false;
            rev=(rev*10)+(x%10);
            x/=10;
        }
        if(old==rev && rev>=0)
        {
            
            return true;
        }
        else
            return false;
        
    }
};
