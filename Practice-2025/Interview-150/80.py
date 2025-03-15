## https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<3:
            return len(nums)
        i = 0
        pos = 1
        ref = nums[0]
        count = 1
        i+=1
        while i < len(nums):
            if nums[i] !=ref:
                ref = nums[i]
                nums[pos] = nums[i]
                pos+=1
                count = 1
                i+=1
            elif nums[i] == ref and count == 1:
                count = 2
                nums[pos] = ref
                pos+=1
                i+=1
            else:
                i += 1
        return pos