# https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

def isPalindrome( s):
        
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip().lower()
        s = ''.join([c for c in s if c.isalnum()])
        return s == s[::-1]

print(isPalindrome("A man, a plan, a canal: Panama"))