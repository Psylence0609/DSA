## https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        symbol = {'I' : 1, 'V' : 5, 'X' : 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        value = 0
        i = 0
        while i < len(s):
            if s[i] == 'I' and i + 1 <len(s) and (s[i+1] == 'V' or s[i+1] == 'X'):
                    value += symbol[s[i+1]] - 1
                    i+=2
                    continue
            elif s[i] == 'X' and i + 1 <len(s) and (s[i+1] == 'L' or s[i+1] == 'C'):
                    value += symbol[s[i+1]] - 10
                    i+=2
                    continue
            elif s[i] == 'C' and i + 1 <len(s) and (s[i+1] == 'D' or s[i+1] == 'M'):
                    value += symbol[s[i+1]] - 100
                    i+=2
                    continue
            value += symbol[s[i]]
            i += 1
        return value