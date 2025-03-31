def minReorder(self, n: int, connections: List[List[int]]) -> int:
        look = {tuple(x): 0 for x in connections}
        visited = set()
        visited.add(0)
        adj = defaultdict(list)
        for i, j in connections:
            adj[i].append(j)
            adj[j].append(i)
        count = 0
        def dfs(i):
            nonlocal count
            nonlocal visited
            for j in adj[i]:
                if j not in visited:
                    if tuple([i,j]) in look:
                        count += 1
                    visited.add(j)
                    dfs(j)
        
        dfs(0)
        return count