## https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k = 0
        for i in range(len(nums)):
            if nums[i] == val:
                k += 1
            else:
                nums[i-k] = nums[i]
        
        return len(nums)-k