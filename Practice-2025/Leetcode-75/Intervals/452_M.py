def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: x[1])
        l = 0
        count = 1
        for r in range(1, len(points)):
            if points[l][1] < points[r][0]:
                l = r
                count += 1
            
        return count