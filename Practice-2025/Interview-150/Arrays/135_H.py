## https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150

def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        total = n
        i = 1
        while i < n:
            if ratings[i] == ratings[i - 1]:
                i += 1
                continue
            current_peak = 0
            while i < n and ratings[i] > ratings[i-1]:
                current_peak += 1
                total += current_peak
                i += 1
            
            if i == n:
                return total
            
            current_valley = 0
            while i < n and ratings[i] < ratings[i-1]:
                current_valley += 1
                total += current_valley
                i += 1
            
            total -= min(current_peak, current_valley)
        
        return total