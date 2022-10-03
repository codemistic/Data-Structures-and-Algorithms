"""
https://leetcode.com/problems/house-robber/
This is a pure Python implementation of Dynamic Programming solution to the House Robber problem.
Time Complexity:O(n)
Space Complexity:O(n)

The problem is :
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Find the maximum amount of money you can rob tonight without alerting the police.

"""
def rob(self, nums: List[int]) -> int:
    
       """
       
       Given an integer array nums representing the amount of money of each house, Th program
       returns the maximum amount of money you can rob tonight without alerting the police.
       
       >>> rob([1,2,3,1])
       4
       Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
       Total amount you can rob = 1 + 3 = 4.
       
       >>>rob([2,7,9,3,1])
       12
       Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
       Total amount you can rob = 2 + 9 + 1 = 12.
       
       """
        dp= [0] * (len(nums) + 2)
        for i in range(2,len(nums)+2):
            dp[i] = max(nums[i-2] + dp[i-2], dp[i-1])
        return dp[len(nums)+1]
        
"""

This is a Python implementation of the House Robber problem with optimised Space Complexity.
Time Complexity: O(n)
Space Complexity: O(1)

"""
def rob(self, nums: List[int]) -> int:
    
        rob1, rob2 = 0, 0
        for n in nums:
            rob1, rob2 = rob2, max(n + rob1, rob2) 
        return rob2
      






        

