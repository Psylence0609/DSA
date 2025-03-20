## https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        left = 0
        right = 1
        max_profit = 0
        while right < len(prices):
            current = prices[right] - prices[left]
            if prices[right]>prices[left]:
                max_profit = max(max_profit, current)
            else:
                left = right
            right+=1
        return max_profit