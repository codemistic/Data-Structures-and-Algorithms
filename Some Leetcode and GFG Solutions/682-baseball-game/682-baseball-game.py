class Solution:
    def calPoints(self, ops: List[str]) -> int:
        x=[]
        for i in ops:
            if i=="+":
                x.append(x[-1]+x[-2])
            elif i=="C":
                x.pop()
            elif i=="D":
                x.append(x[-1]*2)
                
            else:
                x.append(int(i))
        return sum(x)