//LEETCODE- 64. Minimum Path Sum
    def minPathSum(self, grid: List[List[int]]) -> int:
        nR = len(grid)
        nC = len(grid[0])
        adj = [(1, 0), (0, 1)]
        
        @cache
        def dfs(r, c):
            if r == nR - 1 and c == nC - 1:
                return grid[r][c]
            paths = []
            for a, b in adj:
                r2, c2 = r + a, c + b
                if 0 <= r2 < nR and 0 <= c2 < nC:
                    paths.append(dfs(r2, c2))
            return grid[r][c] + min(paths)
        return dfs(0, 0)
