## https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        k = 1
        found = len(nums) - 1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] >= k:
                k = 1
                found = i
            else:
                k += 1
        return True if found == 0 else False