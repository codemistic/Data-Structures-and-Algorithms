class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        
        self.k=k
        self.a=nums
        heapq.heapify(self.a)
        while len(self.a)>k:
            heapq.heappop(self.a)
    
        
    def add(self, val: int) -> int:
        heapq.heappush(self.a,val)
        
        # heapq.heappop(self.a) cannot use this as there can be an empty list and k=1
        while len(self.a)>self.k:
            heapq.heappop(self.a)
        
        return self.a[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)