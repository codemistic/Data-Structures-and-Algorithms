// https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // first thing that comes to my mind is using the set - with O(N) space
        // using two for loop (N^2) 
        // using another array of same size and updating the value if every times
        //element is there
        int slow=0; 
        int fast=0; 
        
        do {
            slow=nums[slow]; 
            fast=nums[nums[fast]]; 
            
        }while (slow !=fast); 
        
        int slow2=0; 
        
        while (slow2!=slow){
            slow2=nums[slow2]; 
            slow=nums[slow]; 
        }
        
        return slow; 
        
    }
};

