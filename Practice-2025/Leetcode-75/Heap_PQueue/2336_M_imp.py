class SmallestInfiniteSet:
    def __init__(self):
        self.heap = []
        self.current = 1

    def popSmallest(self) -> int:
        if not self.heap:
            result = self.current
            self.current += 1
            return result
        return heappop(self.heap)

    def addBack(self, num: int) -> None:
        if self.current > num and num not in self.heap:
            heappush(self.heap, num)