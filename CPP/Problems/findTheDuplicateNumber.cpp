/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?



Solution:*/

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

