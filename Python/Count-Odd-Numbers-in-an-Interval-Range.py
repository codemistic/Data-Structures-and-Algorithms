class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if high%2==0 and low%2==0:
            return (high-low)//2
        elif high%2==0 and low%2!=0:
            return (high-low)//2+1
        elif high%2!=0 and low%2==0:
            return (high-low)//2+1
        else:
            return (high-low)//2+1
