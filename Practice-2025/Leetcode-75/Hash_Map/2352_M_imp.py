def equalPairs(self, grid: List[List[int]]) -> int:
        grid_map ={}
        ans = 0
        for i in grid:
            grid_map[tuple(i)] = grid_map.get(tuple(i), 0) + 1
        
        for i in range(len(grid)):
            temp = []
            for j in range(len(grid)):
                temp.append(grid[j][i])
            if tuple(temp) in grid_map:
                ans+= grid_map[tuple(temp)]
        return ans 