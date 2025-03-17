## https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort(key = len)

        def prefix(w1, w2):
            pref = ''
            for i in range(min(len(w1),len(w2))):
                if w1[i] == w2[i]:
                    pref += w1[i]
                else:
                    break
            return pref
        pref = strs[0]
        for i in range(1, len(strs)):
            pref = prefix(pref, strs[i])
            if pref == '':
                return pref
        
        return pref