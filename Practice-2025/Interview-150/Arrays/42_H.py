## https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        left_height = [0] * n
        right_height = [0] * n
        max_height = height[0]
        for i in range(1, n):
            left_height[i] = max_height
            max_height = max(max_height, height[i])
        max_height = height[n-1]
        for i in range(n-1, -1, -1):
            right_height[i] = max_height
            max_height = max(max_height, height[i])
        total = 0
        # print(left_height)
        # print(right_height)
        for i in range(1, n-1):
            total += max(0, min(left_height[i], right_height[i]) - height[i])
        
        return total