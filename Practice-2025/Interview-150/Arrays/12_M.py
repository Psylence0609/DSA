## https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150

def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ans = ''
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        for i in range(len(symbols)):
            while num >=values[i]:
                ans += symbols[i]
                num -= values[i]

        return ans