import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapq._heapify_max(nums)
        for _ in range(1, k):
            heapq._heappop_max(nums)
        return nums[0]