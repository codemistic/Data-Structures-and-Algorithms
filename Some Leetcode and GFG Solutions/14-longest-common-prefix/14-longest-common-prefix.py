class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        lil= min(strs,key=len)
        for i,j in enumerate(lil):
            
#             i= int, j=char
            for k in strs:
                if k[i]!=j:
                    return lil[:i]
#                 either a string has no. of same chars lower than lil or equal to lil itself 
        return lil