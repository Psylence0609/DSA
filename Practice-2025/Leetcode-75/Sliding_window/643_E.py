def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        cum_sum = 0.0
        for i in range(k):
            cum_sum += nums[i]
        max_sum = cum_sum
        for i in range(k, len(nums)):
            cum_sum = cum_sum - nums[i - k] + nums[i]
            max_sum = max(max_sum, cum_sum)
        return max_sum/k  