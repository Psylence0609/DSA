def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        visited[0] = True  # Start at room 0

        def dfs(room_index):
            for key in rooms[room_index]:
                if 0 <= key < n and not visited[key]:
                    visited[key] = True
                    dfs(key)

        dfs(0)

        return all(visited)