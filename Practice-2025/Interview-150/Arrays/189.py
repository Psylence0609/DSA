## https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        k %= len(nums)

        def reverse(l, r):
            while l<r:
                nums[l],nums[r] = nums[r], nums[l]
                l+=1
                r-=1
        
        reverse(0, len(nums) - 1)
        reverse(0, k - 1)
        reverse(k, len(nums) - 1)