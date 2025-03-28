def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        start = 0
        total = 0
        min_len = 1e+6
        check = False
        for i in range(len(nums)):
            total += nums[i]
            while total >= target:
                check = 1
                if total - nums[start] >= target and start < i:
                    total -= nums[start]
                    start += 1
                else:
                    break
            
            min_len = min(min_len, i - start + 1) if check else min_len
        
        return min_len if min_len != 1e+6 else 0