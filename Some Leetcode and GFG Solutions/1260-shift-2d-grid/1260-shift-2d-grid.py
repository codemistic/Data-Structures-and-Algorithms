class Solution(object):
    def shiftGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        n=len(grid)
        m=len(grid[0])
        k=k%(m*n)
        l=[]
        for i in grid:
            for j in i:
                l.append(j)
        
        l=l[-k:]+l[:-k]
       
        k=0
        for i in range(n):
            for j in range(m):
                grid[i][j]=l[k]
                k+=1
        return grid
                
            