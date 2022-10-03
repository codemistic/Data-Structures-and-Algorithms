"""
https://leetcode.com/problems/first-missing-positive/
Given an unsorted integer array nums, return the smallest missing positive integer.
"""
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        while i<len(nums):
            correct=nums[i]-1
            if nums[i]>0 and correct<len(nums) and  nums[i]!=nums[correct]:
                     nums[i],nums[correct]=nums[correct],nums[i]
            else:
                i+=1
        flag=0
        for j in range(0,len(nums)):
            if nums[j]-1!=j:
                return j+1
        return len(nums)+1
