## https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return 1
        i = 0
        pos = 1
        ref = nums[0]
        while i < len(nums):
            if nums[i] !=ref:
                ref = nums[i]
                nums[pos] = nums[i]
                pos+=1
                i+=1
            else:
                i += 1
        return pos