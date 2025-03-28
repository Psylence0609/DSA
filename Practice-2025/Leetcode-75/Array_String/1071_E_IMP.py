def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if str1 + str2 != str2 + str1:
            return ""
        m = len(str1)
        n = len(str2)
        while n:
            m, n = n, m % n
        
        return str1[:m]