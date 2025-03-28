def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        lst = s.strip().split(' ')
        lst.reverse()
        answer = ''
        for i in lst:
            if i != "":
                answer += i + ' '
        return answer.strip()