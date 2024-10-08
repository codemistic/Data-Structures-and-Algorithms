//Problem Link - https://leetcode.com/problems/super-egg-drop/

class Solution {
public:
    //Time: O(n*k*logn), Space: O(n*k)
    int helper(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            
            int left = helper(k-1, mid-1, memo);
            int right = helper(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     //move to the downward
    
            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        //k means number of eggs, n means number of floors
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return helper(k, n, memo);
    }