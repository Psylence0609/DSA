## https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        table = [0] * 1001
        for cite in citations:
            table[cite] += 1

        h = len(table)
        count = 0
        while count < h:
            h -= 1
            count += table[h]

        return h