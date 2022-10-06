class Solution:
    def twoSum(self, a: List[int], target: int) -> List[int]:
        start=0
        end=len(a)-1
        while start<=end:
            if a[start]+a[end]==target:
                break
            elif a[start]+a[end]>target:
                end-=1
                continue
            elif a[start]+a[end]<target:
                start+=1
                continue
                
        return [start+1,end+1]