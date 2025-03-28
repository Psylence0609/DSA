def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        s = ""
        m = len(word1)
        n = len(word2)
        i=j=0
        while i < m and j < n:
            s += word1[i] + word2[j]
            i += 1
            j += 1
        
        while i < m:
            s += word1[i]
            i += 1
        
        while j < n:
            s += word2[j]
            j += 1
        
        return s