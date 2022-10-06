class Solution:
    def isPalindrome(self, s: str) -> bool:
        # st=[i for i in s.lower() if i.isalnum()]
        # return st==st[::-1]
        i=0
        j=len(s)-1
        while i<=j:
            x=s[i].lower()
            y=s[j].lower()
            if x.isalnum() and y.isalnum():
                if x!=y:
                    return False
                else:
                    i+=1
                    j-=1
                    continue
            if not x.isalnum():
                i+=1
            if not y.isalnum():
                j-=1
                
        return True