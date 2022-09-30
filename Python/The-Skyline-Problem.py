class Solution:
    def getSkyline(self, buildings):
        points  = [(l,h,-1,i) for i, (l,r,h) in enumerate(buildings)]
        points += [(r,h,1,i) for i, (l,r,h) in enumerate(buildings)]
        points.sort(key = lambda x: (x[0], x[1]*x[2]))
        heap, active, ans = [(0,-1)], set([-1]), []
        
        for x, h, lr, ind in points:
            if lr == -1: active.add(ind)
            else: active.remove(ind)
           
            if lr == -1:
                if h > -heap[0][0]: 
                    ans.append([x, h])
                heappush(heap, (-h, ind))
            else:
                if h == -heap[0][0]:   
                    while heap and heap[0][1] not in active: heappop(heap)
                if -heap[0][0] != ans[-1][1]: 
                    ans.append([x, -heap[0][0]])
                
        return ans
