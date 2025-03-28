def maxOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        nums.sort()
        l ,r = 0, len(nums) - 1
        max_op = 0
        while l < r:
            if nums[l] + nums[r] == k:
                max_op += 1
                l += 1
                r -= 1
            elif nums[l] + nums[r] > k:
                r -= 1
            else:
                l += 1
        return max_op