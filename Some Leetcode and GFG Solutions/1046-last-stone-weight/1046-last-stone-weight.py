class Solution:
    def lastStoneWeight(self, s: List[int]) -> int:
        if not s:
            return 0
        elif len(s)==1:
            return s[0]
        elif len(s)==2:
            return abs(s[0]-s[1])
        else:
            x=max(s)
            s.remove(x)
            y=max(s)
            s.remove(y)
            
            if x!=y:
                s.append(abs(x-y))
                
            oof=self.lastStoneWeight(s)
            return oof