def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        num1_dict = {}
        num2_dict = {}

        for i in nums1:
            num1_dict[i] = 1
        for i in nums2:
            num2_dict[i] = 1
        answer = [[],[]]
        for i in num1_dict:
            if i not in num2_dict:
                answer[0].append(i)
        for i in num2_dict:
            if i not in num1_dict:
                answer[1].append(i)
        return answer