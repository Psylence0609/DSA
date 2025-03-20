# https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i = 0
        j = 0

        while i < len(t) and j < len(s):
            if t[i] == s[j]:
                j += 1
            i += 1
        return j == len(s)