## https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150


def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        answer = ''
        if numRows == 1:
            return s
        n = len(s) // (2 * (numRows - 1))
        if len(s) % (2 * (numRows - 1)) > 0:
            n += 1
        for i in range(numRows):
            next_index = i
            while True:
                print('next',next_index)
                if next_index > len(s) - 1:
                    break
                answer += s[next_index]
                if i not in [0, numRows - 1]:
                    temp_index = next_index + (2 * (numRows - 1)) - 2 * i
                    if temp_index > len(s) - 1:
                        break
                    print('temp',temp_index)
                    answer += s[temp_index]
                next_index = next_index + (2 * (numRows - 1))
        return answer