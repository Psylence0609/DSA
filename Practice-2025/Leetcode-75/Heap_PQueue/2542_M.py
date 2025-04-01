def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        z = sorted(zip(nums2, nums1), reverse=True)
        heap = [y for _, y in z[:k]]
        heapify(heap)
        print(heap)
        cur = sum(heap)
        res = cur * z[k-1][0]
        for i, (x, y) in enumerate(z[k:]):
            cur -= heappop(heap)
            cur += y
            heappush(heap, y)
            res = max(res, cur * x)
        return res