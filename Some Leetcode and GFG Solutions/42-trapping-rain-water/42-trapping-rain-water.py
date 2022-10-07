class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        max_before = []
        max_after = []
        m = height[0]
        for i in height:
            m = max(m, i)
            max_before.append(m)
        m = height[-1]
        for i in height[::-1]:
            m = max(m, i)
            max_after.append(m)
        max_after = max_after[::-1]
        l = len(height)
        for i in range(l):
            water += max(0, min(max_before[i], max_after[i]) - height[i])
        return water