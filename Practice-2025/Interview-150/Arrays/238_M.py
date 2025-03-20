## https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        left = [0]*len(nums)
        right = [0]*len(nums)
        left[0] = 1
        right[len(nums) - 1] = 1
        
        for i in range(1,len(nums)):
            left[i] = left[i - 1] * nums[i - 1]
        for i in range(len(nums) - 2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]
        
        for i in range(len(left)):
            left[i] *= right[i]
        return left