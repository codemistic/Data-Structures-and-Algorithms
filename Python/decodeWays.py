"""
    Leetcode 91. Decode ways 
    Method used : Memoization 
"""


def check(s,mp): # Checks if the string is a valid number in the map of numbers
    return int(s in mp.keys())
g_d = dict()
class Solution():
    def helper(self,s,mp):
        if(s in g_d):
            return g_d[s]
        if(s[0] == '0'): # if the string starts with 0, you cannot decode
            return 0
        if(len(s) == 2): # len(s) == 2; two cases : checking two characters(s[0] && s[1]) seperately and the s[0:2] 
            return  check(s[0:2],mp) + self.helper(s[1:],mp)
        if(len(s) == 1 ): 
            return int(s in mp.keys())
        """
            There are two cases 
            * Pick one character from the front 
                * Check if the charcater chosen is valid
            * Pick two character from the front
                * Check if the charcater chosen is valid
            the conditions below help to validate the conditions mentioned here.
        """
        if not check(s[0:2],mp) and check(s[0:1],mp):
            g_d[s] = self.helper(s[1:],mp)
            return g_d[s]
        if not check(s[0:1],mp) and check(s[0:2],mp):
            g_d[s] = self.helper(s[2:],mp)
            return g_d[s]
        g_d[s] = self.helper(s[1:],mp) + self.helper(s[2:],mp)

        return g_d[s]
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp = dict()
        for i in range(1,27):
            mp[str(i)] = chr(64+i)
        # print(mp)
        return self.helper(s,mp)