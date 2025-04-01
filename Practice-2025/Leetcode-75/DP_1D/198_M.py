def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        dp_chosen = [-1] * len(nums)
        dp_chosen[0] = nums[0]
        dp_chosen[1] = max(nums[0],nums[1])
        for i in range(2, len(nums)):
            dp_chosen[i] = max(nums[i] + dp_chosen[i - 2], dp_chosen[i - 1])
        
        return dp_chosen[-1]