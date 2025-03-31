def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        adj = {}
        for x, eq in enumerate(equations):
            i, j = eq
            if i in adj:
                adj[i].add((j, values[x]))
            else:
                adj[i] = set()
                adj[i].add((j, values[x]))
            if j in adj:
                adj[j].add((i, 1.0 / values[x]))
            else:
                adj[j] = set()
                adj[j].add((i, 1.0 / values[x]))
        
        def dfs(var, parent, target, cummulative):
            nonlocal visited
            for tup in list(adj[var]):
                if tup[0] not in visited:
                    visited.add(tup[0])
                    adj[parent].add((tup[0], cummulative * tup[1]))
                    dfs(tup[0], parent, target, cummulative * tup[1])
        result = []
        for query in queries:
            print(query)
            x, y = query
            if x not in adj:
                result.append(-1)
                continue
            if x == y:
                result.append(1)
                continue
            visited = set()
            visited.add(x)
            dfs(x, x, y, 1)
            check = 0
            for edge in list(adj[x]):
                i, j = edge
                if i == y: 
                    result.append(j)
                    check = 1
                    break
            if check == 0:
                result.append(-1)
        return result