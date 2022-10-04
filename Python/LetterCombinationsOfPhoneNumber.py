"""

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

"""
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        val=""
        finalset=[]
        count=0
        dic={
            2:"abc",
            3:"def",
            4:"ghi",
            5:"jkl",
            6:"mno",
            7:"pqrs",
            8:"tuv",
            9:"wxyz",
        }
        if len(digits)==0:
            return finalset
        def letter(nums,digits,count,val):
            if count==len(nums):
                finalset.append(val)
                return
            a=int(digits[0])
            p=dic[a]
            for i in range(0,len(p)):
                letter(nums,digits[1:],count+1,val+p[i])
        letter(digits,digits,0,val)
        return finalset
                
            
