def largestAltitude(self, gain: List[int]) -> int:
        max_height = 0
        current = 0
        for i in gain:
            current += i
            max_height = max(max_height, current)
        return max_height