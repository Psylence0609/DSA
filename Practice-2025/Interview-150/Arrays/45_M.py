## https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        near = far = jumps = 0

        while far < len(nums) - 1:
            farthest = 0
            for i in range(near, far + 1):
                farthest = max(farthest, i + nums[i])
            
            near = far + 1
            far = farthest
            jumps += 1
        
        return jumps