def orangesRotting(self, grid: List[List[int]]) -> int:
        directions = [(1,0), (0, 1), (-1, 0), (0, -1)]
        rows = len(grid)
        cols = len(grid[0])
        time = [[float('inf')]*len(grid[0]) for _ in range(len(grid))]

        def BFS():
            nonlocal q
            nonlocal directions
            nonlocal rows
            nonlocal cols
            nonlocal time
            nonlocal temp
            while q:
                x, y, t = q.popleft()
                time[x][y] = min(time[x][y], t)
                for dx, dy in directions:
                    new_x, new_y = x + dx, y + dy
                    if 0 <= new_x < rows and 0 <= new_y < cols and (temp[new_x][new_y] in [1, 2]):
                        temp[new_x][new_y] = 3
                        q.append((new_x, new_y, t + 1))
        q = deque([])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    grid[i][j] = 3
                    temp = [row[:] for row in grid]
                    q.append((i, j, 0))
                    BFS()
                    # print(temp)
        max_time = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1 and time[i][j] == float('inf'):
                    return -1
                if time[i][j] != float('inf'):
                    max_time = max(max_time, time[i][j])
        # print(time)
        return max_time