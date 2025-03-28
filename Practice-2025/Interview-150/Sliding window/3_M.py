# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = max_len = 0
        last = {}

        for i, ch in enumerate(s):
            if ch in last and last[ch] >= left:
                left = last[ch] + 1
            max_len = max(max_len, i - left + 1)
            last[ch] = i
        return max_len