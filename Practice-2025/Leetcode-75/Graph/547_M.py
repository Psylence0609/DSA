def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [0] * n
        count = 0
        def dfs(i):
            for j in range(n):
                if not visited[j] and isConnected[i][j] and i!= j: 
                    visited[j] = 1
                    dfs(j)
        for i in range(n):
            if visited[i]: continue
            count += 1
            dfs(i)
        return count