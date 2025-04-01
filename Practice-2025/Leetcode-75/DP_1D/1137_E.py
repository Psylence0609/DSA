def tribonacci(self, n: int) -> int:
        nums = [0,1,1] 
        for i in range(3, n + 1):
            nums[0],nums[1],nums[2] = nums[1],nums[2], nums[0]+nums[1]+nums[2]
        return nums[-1] if n > 2 else nums[n]