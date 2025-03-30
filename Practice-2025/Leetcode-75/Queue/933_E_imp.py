class RecentCounter:

    def __init__(self):
        self.rec = []
        self.start = 0

    def ping(self, t: int) -> int:
        self.rec.append(t)
        while self.rec[self.start] < t - 3000:
            self.start += 1
        return len(self.rec) - self.start