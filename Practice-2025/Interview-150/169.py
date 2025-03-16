## https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150

def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        high = 0
        count = 0

        for i in nums:
            if i != high:
                count -= 1
            else:
                count += 1
            if count < 0:
                high = i
                count = 1
        return high