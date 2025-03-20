# https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150

def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        set_triplets = set()
        nums.sort()
        def twoSum(numbers, target):
            l = 0
            r = len(numbers) - 1
            answers = []
            while l < r:
                if numbers[l] + numbers[r] == target:
                    answers.append([l+1, r+1])
                    r -= 1
                    l += 1
                elif numbers[l] + numbers[r] > target:
                    r -= 1
                else:
                    l += 1
            return answers
        for i in range(len(nums) - 2):
            two_sum = 0 - nums[i]
            
            result_set = twoSum(nums[i + 1:], two_sum)
            for result in result_set:
                set_triplets.add((nums[i], nums[i  + result[0]], nums[i + result[1]]))
        
        triplets = []
        for triplet in set_triplets:
            triplets.append([item for item in triplet])
        
        return triplets