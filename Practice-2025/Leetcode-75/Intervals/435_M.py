def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: x[1])
        # print(intervals)
        count = 0
        l,r = 0,1
        while r != len(intervals):
            if intervals[l][1] > intervals[r][0]:
                count += 1
            else:
                l = r
            r += 1
        return count